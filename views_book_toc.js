Drupal.behaviors.views_book_toc = function() {
  // make sure all the parent li elements of our active menu link are classed 'open'
  $('#book-toc li.open').parents('li').addClass('open');
  $('#book-toc a.no-content').attr('href', '#');
  $('#book-toc a.no-content').click(function() {
    $(this).parent('span').prev('div.hitarea').click();
    return false;
  });
  // start the tree plugin, collapsed except for active menu path.
  $('#book-toc').treeview({'collapsed': 1});
}
