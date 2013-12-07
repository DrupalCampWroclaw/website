<?php
// $Id: $

$_SERVER['REMOTE_ADDR'] = 'example.com';
$_SERVER['HTTP_HOST'] = 'example.com';



print "=========== Current dir: $current_dir \n";

switch ($current_dir) {
  case '/var/lib/jenkins/workspace/wouworld_dev/app':
   $test_host = 'www.dev.wouworld.s1v1.droptica.org';
  break;
  case '/home/gbartman/openBIT/www2/wouworld/app':
    $test_host = 'www.wouworld.gbartman';
  break;
  default:
    $test_host = 'example.com';
  break;
}

print "=========== test_host: $test_host \n";

$_SERVER['REMOTE_ADDR'] = $test_host;
$_SERVER['HTTP_HOST'] = $test_host;

/**
 * @file
 * PHPunit helper functions for Drupal tests.
 * Drupal 7
 *
 * Author: grzegorz.bartman@openbit.pl
 * Version: 3.0
 */
require_once 'includes/bootstrap.inc';
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

abstract class PHPUnit_Drupal extends PHPUnit_Framework_TestCase {

  protected $time, $nodesList, $usersList, $commentsList, $variables;
  protected $database;

  function __construct() {
    $this->time = time();
  }

  function __destruct() {
    //Remove test comments
    if (isset($this->commentsList)) {
      foreach ($this->commentsList as $cid) {
        $this->commentDelete($cid);
      }
    }

    //Remove test nodes
    if (isset($this->nodesList)) {
      foreach ($this->nodesList as $node) {
        $this->nodeDelete($node);
      }
    }

    //Remove test users
    if (isset($this->usersList)) {
      foreach ($this->usersList as $uid) {
        $this->userDelete($uid);
      }
    }

    // Restore variables.
    if (isset($this->variables)) {
      foreach ($this->variables as $name => $value) {
        variable_set($name, $value);
      }
    }

    // Remove test terms
    if (isset($this->terms)) {
      foreach ($this->terms as $tid) {
        taxonomy_del_vocabulary($vid);
      }
    }

    // Remove test vocabularies
    if (isset($this->vacabularies)) {
      foreach ($this->vocabularies as $vid) {
        taxonomy_del_vocabulary($vid);
      }
    }
  }

  public function setUp() {
    global $db_url;
    if(is_array($db_url))
      $url = parse_url($db_url['default']);
    elseif(!is_array($db_url))
      $url = parse_url($db_url);
    $this->database = substr($url['path'], 1);
  }

  public function tearDown() {

  }

  /**
   * Display debug information
   * @param $name
   *  Title
   * @param $variable
   *  Variable to display in print_r() function
   */
  protected function displayDebug($name, $variable) {
    print '
        ' . $name . ':
        ';
    print_r($variable);
    print '
        Memory usage:' . (memory_get_usage() / 1024 / 1024) . ' MB
        ';
    print '
        Time: ' . (time() - $this->time) . ' seconds
        ';
  }

  /**
   * Delete nodes.
   *
   * @param  $node
   *  Node object
   */
  protected function nodeDelete($node) {
    //delete node
    db_unlock_tables();

    db_query('DELETE FROM {node} WHERE nid = %d', $node->nid);
    db_query('DELETE FROM {node_revisions} WHERE nid = %d', $node->nid);
    // Call the node-specific callback (if any):
    node_invoke($test_node, 'delete');
    node_invoke_nodeapi($test_node, 'delete');
    watchdog('phpunit', 'Deleted node: %title .', array('title' => $node->title));
  }

  /**
   * Creates node.
   *
   * @param $params
   *  Array of node object attributes : type='page', title, body, uid=1,
   *  status=1, comment=2 are automatically generated if no exists.
   * @return
   *  Node object after save
   */
  protected function nodeSave($params = array(), $debug = FALSE) {

    if (!isset($params['type'])) {
      $params['type'] = 'page';
    }
    if (!isset($params['title'])) {
      $params['title'] = 'Test node title ' . rand(1000, 100000);
    }
    if (!isset($params['body'])) {
      $params['body'] = 'Test node body ' . rand(1000, 100000);
    }
    if (!isset($params['uid'])) {
      $params['uid'] = 1;
    }
    if (!isset($params['status'])) {
      $params['status'] = 1;
    }
     if (!isset($params['comment'])) {
      $params['comment'] = 2;
    }


    $node = new stdClass();

    foreach ($params as $key => $value) {
      $node->$key = $value;
    }

    db_unlock_tables();
    node_save($node);

    //Debug
    if ($debug) {
      $this->displayDebug('Saved node', $node);
    }

    //Save node to remove in destructor
    $this->nodesList[] = $node;

    return $node;
  }


  /**
   *Create test user
   * @param $params
   *  User account parameters. Parameters: "name, mail, status, pass, roles"
   *  are generated automatically if no exists.
   * @param $debug
   *  Default = FALSE
   * @return
   *  New user object
   */
  protected function userSave($params = array(), $debug = FALSE) {

    if (!isset($params['name'])) {
      $params['name'] = 'Test user ' .  rand(1000, 100000);
    }
    if (!isset($params['mail'])) {
      $params['mail'] = 'mail-' .  rand(1000, 100000) . '@example.com';
    }
    if (!isset($params['status'])) {
      $params['status'] = 1;
    }
    if (!isset($params['pass'])) {
      $params['pass'] = '123';
    }
    if (!isset($params['roles'])) {
      $params['roles'] = array(2 => 'authenticated user');
    }

    //Prepare user data to save
    foreach($params as $key => $value) {
      $user[$key] = $value;
    }

    //db_unlock_tables();
    if(isset($params['uid'])) {
      $account->uid = $params['uid'];
    }
    else {
      $account = NULL;
    }
    $new_user = user_save($account, $user);

    //Debug
    if ($debug) {
      $this->displayDebug('User', $new_user);
    }

    $this->usersList[] = $new_user->uid;

    return $new_user;
  }

  /**
   * Delete user
   * @param $uid
   */
  protected function userDelete($uid) {
    db_unlock_tables();
    $account = user_load(array('uid' => $uid));
    sess_destroy_uid($uid);
    _user_mail_notify('status_deleted', $account);
    db_query('DELETE FROM {users} WHERE uid = %d', $uid);
    db_query('DELETE FROM {users_roles} WHERE uid = %d', $uid);
    db_query('DELETE FROM {authmap} WHERE uid = %d', $uid);
    $variables = array('%name' => $account->name, '%email' => '<' . $account->mail . '>');
    watchdog('phpunit', 'Deleted user: %name %email.', $variables);
    user_module_invoke('delete', $edit, $account);
  }
  /**
   * Login user
   * @param $uid
   *  User UID
   */
  protected function userLogin($username, $password) {
    print "NOT WORKING IN DRUPAL 7!";
    return;

/*
    $form_state = array();
$form_state['values']['name'] = $username;
$form_state['values']['pass'] = $password;
$form_state['values']['op'] = t('Log In');



drupal_execute('user_login', $form_state);
return;


    $form_values = array();
    $form_values["name"] = $username;
    $form_values["pass"] = $password;
    $form_values["op"] = "Log in";

    print "==== userLogin $username ".print_r($form_values, TRUE)."\n ";

    return user_authenticate($form_values);

    global $user;
    $user = user_load($uid);
    drupal_session_regenerate();*/

/*     global $user;
      $user = user_load($uid);

      $login_array = array ('name' => $user->name);
      user_login_finalize($login_array);*/

  /*  $form_state['uid'] = $uid;
    user_login_submit(array(), $form_state);*/

    /*  return;

    $userObj = user_load(array('uid' => $uid));
    global $user;
    $user = $userObj;

    //Log in user
    $userObj->login = time();
    //db_unlock_tables();
    db_query("UPDATE {users} SET login = :login WHERE uid = :uid", array(':login' => $userObj->login, ':uid' => $userObj->uid));

    // Regenerate the session ID to prevent against session fixation attacks.
    sess_regenerate();
    user_module_invoke('login', $edit, $userObj);*/
  }

  /**
   * Log out user.
   *
   * @global $user;
   */
  function userLogout() {
    global $user;

    // Destroy the current session:
    session_destroy();
    // Only variables can be passed by reference workaround.
    $null = NULL;
    user_module_invoke('logout', $null, $user);

    // Load the anonymous user
    $user = drupal_anonymous_user();
  }

  /**
   * Create comment
   * @param $nid
   *  Node ID
   * @param $params
   *  Array of comment paraeters (pid, uid, name, mail, comment, subject,
   *  homepage, timestamp, hostname, status, format). If params no exists are
   *  generated automatically
   * @param $debug
   *  Set to TRUE if want to display debug information
   * @return
   *  Comment ID
   */
  protected function commentSave($nid, $params = array(), $debug = FALSE) {

    $node_comment['nid'] = $nid;

    if (!isset($params['pid'])) {
      $params['pid'] = 0;
    }
    if (!isset($params['uid'])) {
      $params['uid'] = 1;
    }
    if (!isset($params['name'])) {
      $params['name'] = 'Name-' . rand(1000, 100000);
    }
    if (!isset($params['mail'])) {
      $params['mail'] = 'mail-' . rand(1000, 100000) . '@example.com';
    }
    if (!isset($params['comment'])) {
      $params['comment'] = 'comment-' . rand(1000, 100000);
    }
    if (!isset($params['subject'])) {
      $params['subject'] = 'subject-' . rand(1000, 100000);
    }
    if (!isset($params['homepage'])) {
      $params['homepage'] = 'http://www.openbit.pl';
    }
    if (!isset($params['timestamp'])) {
      $params['timestamp'] = time();
    }
    if (!isset($params['hostname'])) {
      $params['hostname'] = $_SERVER['REMOTE_ADDR'];
    }
    if (!isset($params['status'])) {
      $params['status'] = COMMENT_PUBLISHED;
    }
    if (!isset($params['format'])) {
      $params['format'] = 2;
    }


    foreach ($params as $key=>$value) {
      $node_comment[$key] = $value;
    }

    db_unlock_tables();
    $comment_id = comment_save($node_comment);

    if ($debug) {
      $this->displayDebug('Comment', $node_comment);
      $this->displayDebug('Comment id', $comment_id);
    }

    $this->commentsList[] = $comment_id;

    return $comment_id;
  }

  /**
   * Delete comment
   * @param $cid
   *  Comment ID
   */
  protected function commentDelete($cid) {
    db_unlock_tables();
    db_query('DELETE FROM {comments} WHERE cid = %d', $cid);
    watchdog('phpunit', 'Deleted comment: %cid .', array('cid' => $cid));
  }

  /**
   * Set variable. All variables are restored after tests.
   *
   * @param $name
   *   Variable name.
   * @param $value
   *   Variable value.
   */
  protected function variableSet($name, $value) {
    $deafult = '';
    if(!isset($this->variables[$name])) {
      $this->variables[$name] = variable_get($name, $default);
    }
    variable_set($name, $value);
  }

  /**
  * Get variable.
  *
  * @param $name
  *   Variable name.
  * @param $default
  *  Default value.
  *
  * @return
  *   Variable value.
  */
  protected function variableGet($name, $default) {
   return variable_get($name, $default);
  }

  /**
   * Check is column in table in database.
   *
   * @param $table
   *   Table name.
   * @param $column
   *   Column name.
   * @param $database
   *   Database name.
   *
   * @return
   *   TRUE if column exists.
   */
  protected function isColumnInTable($table, $column, $database) {
    db_unlock_tables();
    $count = db_result(db_query("SELECT count(*) FROM INFORMATION_SCHEMA.COLUMNS
          WHERE TABLE_NAME = '%s'
          AND COLUMN_NAME = '%s'
          AND TABLE_SCHEMA = '%s'", $table, $column, $database));
    return 1 == $count;
  }

  /**
   * Check database tables.
   */
  protected function checkTables($array, $database) {
    foreach($array as $table => $columns ) {
      foreach($columns as $column) {
        $this->assertEquals(TRUE, $this->isColumnInTable($table, $column, $database));
      }
    }
  }


  /**
   * Create taxonomy term.
   *
   * @param $term
   * @param $debug
   *
   * @return
   *   Term object.
   */
  protected function termCreate($term, $debug = FALSE) {
    if (!isset($term['vid'])) {
      return;
    }

    if (!isset($term['name'])) {
      $term['name'] = 'Test term ' . rand(1000, 100000);
    }
    taxonomy_save_term($term);
    if ($debug) {
      $this->displayDebug('Term', $term);
    }
    $terms[] = $term['tid'];
    return $term;
  }

  /**
   * Create taxonomy vocabulary.
   *
   * @param $vocabulary
   *   Vocabulary array.
   * @param $debug
   *
   * @return
   *   Vocabulary object.
   */
  protected function vocabularyCreate($vocabulary, $debug = FALSE) {
    $vocabulary = array(
      // Human readable name of the vocabulary
      'name' => isset($vocabulary['name']) ? $vocabulary['name'] :
        'Test vocabulary ' . rand(1000, 100000),
      // Set 1 to allow multiple selection.
      'multiple' => isset($v['multiple']) ? $v['multiple'] : 0,
      // Set 1 to make the terms mandatory to be selected.
      'required' => isset($v['required']) ? $v['required'] : 0,
      // Set 1 to allow and create hierarchy of the terms within the vocabulary.
      'hierarchy' => isset($v['hierarchy']) ? $v['hierarchy'] : 0,
      // Set 1 to set and allow relation amongst multiple terms
      'relations' => isset($v['relations']) ? $v['relations'] : 0,
      // Set the node to which this vocabulary will be attached to.
      'nodes' => isset($v['nodes']) ? $v['nodes'] : array(),
      // Set the weight to display the vocabulary in the list.
      'weight' => isset($v['weight']) ? $v['weight'] : 0,
    );

    if (isset($vocabulary['module'])) {
      $vocabulary['module'] = $v['module'];
    }

    taxonomy_save_vocabulary($vocabulary);
    if ($debug) {
      $this->displayDebug('Vocabulary', $vocabulary);
    }
    return $vocabulary;
  }

    /*
   * @TODO
   * roleCreate
   * drupalPost($path, $edit, $submit) - Execute a POST request on a Drupal page (submit form)
   */

}