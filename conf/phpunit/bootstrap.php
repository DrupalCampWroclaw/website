<?php

$current_dir = getcwd();


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

define('DRUPAL_ROOT', $current_dir);
require_once dirname(__FILE__).'/../../app/includes/bootstrap.inc';
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);
global $base_url;

$base_url = 'http://'.$test_host;

