<?php
/**
 * @file
 * Returns the HTML for a single Drupal page.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728148
 */
?>

<div id="page-all">

  <div id="header-over-bg">
    <div id="header-over">
      <div id="header-bar" class="clearfix">
        <div id="header-bar-center">
         <div id="header-bar-left">
         </div>
          <div id="header-bar-center-text" class="clearfix">
            <div id="conference-statistics"><?php print $confstats; ?></div>
            <div id="user-links"><?php print $userlinks; ?></div>
            <?php /*<div id="social-links" ><?php print $sociallinks; ?></div>*/ ?>
          </div>

          <div id="header-bar-right">
          </div>
        </div>
      </div>
    </div>
  </div>

  <div id="mainmenu-over">
    <div id="mainmenu" class="clearfix">
      <?php print render($page['navigation']); ?>
    </div>
  </div>

  <div id="main-over">
    <div id="main">

      <div id="content" class="column" role="main">
        <?php print render($page['highlighted']); ?>
        <?php print $breadcrumb; ?>
        <a id="main-content"></a>
        <?php print render($title_prefix); ?>
        <?php if ($title): ?>
          <h1 class="page__title title" id="page-title"><?php print $title; ?></h1>
        <?php endif; ?>
        <?php print render($title_suffix); ?>
        <?php print $messages; ?>
        <?php print render($tabs); ?>
        <?php print render($page['help']); ?>
        <?php if ($action_links): ?>
          <ul class="action-links"><?php print render($action_links); ?></ul>
        <?php endif; ?>
        <?php print render($page['content_top']); ?>
        <?php print render($page['content']); ?>
        <?php print render($page['content_bottom']); ?>
        <?php print $feed_icons; ?>
      </div>


      <?php
        // Render the sidebars to see if there's anything in them.
        $sidebar_first  = render($page['sidebar_first']);
        $sidebar_second = render($page['sidebar_second']);
      ?>

      <?php if ($sidebar_first || $sidebar_second): ?>
        <aside class="sidebars">
          <?php print $sidebar_first; ?>
          <?php print $sidebar_second; ?>
        </aside>
      <?php endif; ?>

    </div>
  </div>  <!-- end main-over -->

  <?php print render($page['footer']); ?>

</div>

<?php print render($page['bottom']); ?>
