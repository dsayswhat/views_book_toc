<?php


function views_book_toc_views_plugins() {
  return array(
      'style' => array( // Declare the nested list style plugin.
        'book_toc' => array(
          'title' => t('Book table of contents'),
          'theme' => 'views_view_book_toc',
          'help' => t('Displays rows in a nested list, based on book hierarchy'),
          'handler' => 'views_plugin_style_book_toc',
          'uses row plugin' => TRUE,
          'uses fields' => TRUE,
          'uses grouping' => TRUE,
          'uses options' => TRUE,
          'type' => 'normal',
          'parent' => 'list',
          ),
        )
      );
}
