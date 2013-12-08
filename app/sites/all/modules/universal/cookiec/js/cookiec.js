(function ($) {
  Drupal.behaviors.cookiec_popup = {
    attach: function(context, settings) {
      $('body').not('.sliding-popup-processed').addClass('sliding-popup-processed').each(function() {
        try {
          var enabled = Drupal.settings.cookiec.popup_enabled;
          if(!enabled) {
            return;
          }
          if (!Drupal.cookiec.cookiesEnabled()) {
            return;
          }
          var status = Drupal.cookiec.getCurrentStatus();
          console.log(status);
          var agreed_enabled = Drupal.settings.cookiec.popup_agreed_enabled;
          var popup_hide_agreed = Drupal.settings.cookiec.popup_hide_agreed;
          if (status == 0) {
            var next_status = 1;
            $('a, input[type=submit]').bind('click.cookiec', function(){
              if(!agreed_enabled) {
                Drupal.cookiec.setStatus(1);
                next_status = 2;
              }
              Drupal.cookiec.changeStatus(next_status);
            });

            $('.agree-button').click(function(){
              if(!agreed_enabled) {
                Drupal.cookiec.setStatus(1);
                next_status = 2;
              }
              Drupal.cookiec.changeStatus(next_status);
            });

            Drupal.cookiec.createPopup(Drupal.settings.cookiec.popup_html_info);
          } else if(status == 1) {
            Drupal.cookiec.createPopup(Drupal.settings.cookiec.popup_html_agreed);
            if (popup_hide_agreed) {
              $('a, input[type=submit]').bind('click.cookiec_hideagreed', function(){
                Drupal.cookiec.changeStatus(2);
              });
            }

          } else {
            return;
          }
        }
        catch(e) {
          return;
        }
      });
    }
  }

  Drupal.cookiec = {};

  Drupal.cookiec.createPopup = function(html) {
    var popup = $(html)
      .attr({"id": "sliding-popup"})
      .height(Drupal.settings.cookiec.popup_height)
      .width(Drupal.settings.cookiec.popup_width)
      .hide();
      console.log(popup);
    if(Drupal.settings.cookiec.popup_position) {
      popup.prependTo("body");
      var height = popup.height();
      popup.show()
        .attr({"class": "sliding-popup-top"})
        .css({"top": -1 * height})
        .animate({top: 0}, Drupal.settings.cookiec.popup_delay);
    } else {
      popup.appendTo("body");
      height = popup.height();
      popup.show()
        .attr({"class": "sliding-popup-bottom"})
        .css({"bottom": -1 * height})
        .animate({bottom: 0}, Drupal.settings.cookiec.popup_delay)
    }
    Drupal.cookiec.attachEvents();
  }

  Drupal.cookiec.attachEvents = function() {
    var agreed_enabled = Drupal.settings.cookiec.popup_agreed_enabled;
    $('.find-more-button').click(function(){
      window.open(Drupal.settings.cookiec.popup_link);
    });
    $('.agree-button').click(function(){
      var next_status = 1;
      if(!agreed_enabled) {
        Drupal.cookiec.setStatus(1);
        next_status = 2;
      }
      $('a, input[type=submit]').unbind('click.cookiec');
      Drupal.cookiec.changeStatus(next_status);
    });
    $('.hide-popup-button').click(function(){
      Drupal.cookiec.changeStatus(2);
    });
  }

  Drupal.cookiec.getCurrentStatus = function() {
    var search = 'cookie-agreed-'+Drupal.settings.cookiec.popup_language+'=';
    var offset = document.cookie.indexOf(search);
    if (offset < 0) {
      return 0;
    }
    offset += search.length;
    var end = document.cookie.indexOf(';', offset);
    if (end == -1) {
      end = document.cookie.length;
    }
    var value = document.cookie.substring(offset, end);
    return parseInt(value);
  }

  Drupal.cookiec.changeStatus = function(value) {
    var status = Drupal.cookiec.getCurrentStatus();
    if (status == value) return;
    if(Drupal.settings.cookiec.popup_position) {
      $(".sliding-popup-top").animate({top: $("#sliding-popup").height() * -1}, Drupal.settings.cookiec.popup_delay, function () {
        if(status == 0) {
          $("#sliding-popup").html(Drupal.settings.cookiec.popup_html_agreed).animate({top: 0}, Drupal.settings.cookiec.popup_delay);
          Drupal.cookiec.attachEvents();
        }
        if(status == 1) {
          $("#sliding-popup").remove();
        }
      })
    } else {
      $(".sliding-popup-bottom").animate({bottom: $("#sliding-popup").height() * -1}, Drupal.settings.cookiec.popup_delay, function () {
        if(status == 0) {
          $("#sliding-popup").html(Drupal.settings.cookiec.popup_html_agreed).animate({bottom: 0}, Drupal.settings.cookiec.popup_delay)
          Drupal.cookiec.attachEvents();
        }
        if(status == 1) {
          $("#sliding-popup").remove();
        }
      ;})
    }
    Drupal.cookiec.setStatus(value);
  }

  Drupal.cookiec.setStatus = function(status) {
    var date = new Date();
    date.setDate(date.getDate() + 100);
    document.cookie = "cookie-agreed-"+Drupal.settings.cookiec.popup_language + "="+status+";expires=" + date.toUTCString() + ";path=" + Drupal.settings.basePath;
  }

  Drupal.cookiec.hasAgreed = function() {
    var status = Drupal.cookiec.getCurrentStatus();
    if(status == 1 || status == 2) {
      return true;
    }
    return false;
  }

  Drupal.cookiec.cookiesEnabled = function() {
    var cookieEnabled = (navigator.cookieEnabled) ? true : false;
      if (typeof navigator.cookieEnabled == "undefined" && !cookieEnabled) {
        document.cookie="testcookie";
        cookieEnabled = (document.cookie.indexOf("testcookie") != -1) ? true : false;
      }
    return (cookieEnabled);
  }

})(jQuery);
