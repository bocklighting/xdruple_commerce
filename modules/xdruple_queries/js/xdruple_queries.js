(function ($) {
  $(document).ready(function () {
    categoryAccordion();
  });

  var categoryAccordion = function () {
    $(".b-categories-accordion .panel-body").accordion({
      active: false,
      collapsible: true,
      heightStyle: "content",
      header: ".accordion-item-title",
      icons: null
    });
  };

})(jQuery);
