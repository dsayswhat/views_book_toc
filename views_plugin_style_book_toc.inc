<?php
/**
 * Implements views_plugin_style.
 */
class views_plugin_style_book_toc extends views_plugin_style_list {

  function render() {
    module_load_include('inc', 'filefield', 'filefield.theme');
    if ($path = libraries_get_path('treeview')) {
      drupal_add_js($path . '/jquery.treeview.js', 'module');
      drupal_add_css($path . '/jquery.treeview.css');
      drupal_add_js(drupal_get_path('module', 'views_book_toc') . '/views_book_toc.js', 'module');
    }
    $output = '<ul id="book-toc" class="filetree">';
    foreach ($this->view->result as $key => $row) {
      $nodetype = 'file';   
      $previous_level = $this->view->result[$key-1]->book_menu_links_depth;
      $current_level = $row->book_menu_links_depth;
      $next_level = $this->view->result[$key+1]->book_menu_links_depth;

      if ($next_level > $current_level) { $nodetype = 'folder'; }
      $folder_class = 'has-content';
      if (empty($row->node_revisions_body) && $nodetype == 'folder' ) {
        $folder_class = 'no-content';
      }
      $link = l($row->node_title, "node/$row->nid", array('attributes' => array('class' => $folder_class))) . $row->icon;
      $branchstate = '';
      if (strpos($link,'active')) { $branchstate = 'open'; }

        $file->filemime = $row->files_node_data_field_file_attachment_filemime;
        $file->fid = $row->files_node_data_field_file_attachment_fid;
        $file->filename = $row->files_node_data_field_file_attachment_filename;
        $file->filesize = $row->files_node_data_field_file_attachment_filesize;

//       $output .= "<li class='$branchstate'><span class='$nodetype'>".$link."</span>";
       $output .= "<li class='$branchstate'><span>";
       if ($file->fid) { $output .= theme_filefield_icon($file); }
       $output .= $link;
       $output .= "</span>";

      if ($next_level > $current_level ) {
        $output .= "<ul>";
      }elseif ($next_level < $current_level) {
        $output .= str_repeat("</ul></li>", $current_level - $next_level);
      }else{
        $output .= "</li>";
      }
    }
    return $output;
  }
}
