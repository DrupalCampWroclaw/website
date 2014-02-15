<?php

function cookiec_policy_page() {
  global $language;

  $langcode = cookiec_get_langcode($language);

  $policy = "";

  $regional_function = 'cookiec_policy_text_' . $langcode;

  if(function_exists ($regional_function)) {
    $policy = $regional_function($langcode);
  }
  else{
    $policy = cookiec_policy_text_en($langcode);
  }

  return $policy;
}

function cookiec_policy_settings_en($lang) {
  $settings = array();

  $settings['popup_enabled'] = TRUE;
  $settings['popup_agreed_enabled'] = FALSE;
  $settings['popup_hide_agreed'] = TRUE;
  $settings['popup_width'] = '100%';
  $settings['popup_delay'] = 0;
  $settings['popup_link'] = 'cookiec';
  $settings['popup_position'] = 'top';
  $settings['popup_language'] = $lang;
  $settings['popup_info']['value'] = 'This website uses cookies. By remaining on this website you agree to our <a href="/cookiec">cookie policy</a>';
  $settings['popup_agreed']['value'] = 'I agree';

  return $settings;
}
function cookiec_policy_text_en($lang) {
  $text = '<h2>Cookie Policy</h2>

    <p>This website does not automatically collect any information other than that contained in cookie files.</p>
    <p>The party which saves cookie files in website user\'s device and which gains access to these files is the website operator.</p>
    <p>Cookie files are data, in particluar held as text files, which is stored on the end device of the website\'s user. Cookies usually contain name of the website from which they come, time for which they are to be stored and a unique number.</p>
    <p>Cookie files are used:</p>
    <ul>
      <li>to adjust website content to user preferences and to optimise the use of websites; in particular cookies allow to identify user\'s device and display the website according to his personal needs;</li>

      <li>to gather statistics, which help understand how users interact with the website. This helps to better organise it\'s content and structure;</li>

      <li>to keep user\'s session after the user logs in. Thanks to this, user does not have to enter his login and password on each subsequent page of the website;</li>
    </ul>

    <p>The website uses 2 particular types of cookie files: session cookies and persistent cookies. Session cookies are temporary files which are held in users device until the user logs out and leaves the website or turns off his software (web browser). Persistent cookies are held on users device for a period of time determined by the information held in the cookie or untill they are removed by the user.</p>

    <p>The website uses the following types of cookie files:</p>

    <ul>
      <li>„essential” cookie files, enabling the usage of the services offered by the website, eg. authentication files enabling users to use services requiring authentication;</li>

      <li>cookie files used to provide security, eg. used to idenitfy abuse of authentication mechanisms on the website;</li>

      <li>„performance” cookie files, which enable collecting information about the way users interact with the website;</li>

      <li>„functional” cookie files, which allow for "remembering" of options chosen by the user  and personalisation of user interface, eg. setting his language or region he comes from, preffered font-size, etc.;</li>

      <li>„advertisement” cookie files, which enable providing advertisement content adjusted to users interensts.</li>


    <p>Im many cases, the software used to browse web pages (web browsers) implicitly allows to store cookie files in end user\'s device. Website\'s users can change these settings at any time. The settings can be, in particular, changed to block automatic cookie handling or to inform each time a cookie is saved to users device. Detailed information on the methods and options of handling cookie files are available in the settings section of user\'s device (web browser).</p>
    <p>The website operator informs, that restricting usage of coockies may impact the usability of services offered by the website.</p>
    <p>Cookie files saved in website user\'s device can be used by website operator\'s cooperating partners and advertisers.</p>
    <p>More information on cookie files is available in the \'Help\' section of the web browser.</p>';

  return $text;
}

function cookiec_policy_settings_pl($lang) {
  $settings = array();

  $settings['popup_enabled'] = TRUE;
  $settings['popup_agreed_enabled'] = FALSE;
  $settings['popup_hide_agreed'] = TRUE;
  //$settings['popup_height'] = '50px';
  $settings['popup_width'] = '100%';
  $settings['popup_delay'] = 0;
  $settings['popup_link'] = 'cookiec';
  $settings['popup_position'] = 'top';
  $settings['popup_language'] = $lang;

  $site_name = variable_get('site_name', NULL);
  $settings['popup_info']['value'] = 'Powiadomienie o plikach cookie. Strona ' . $site_name . ' korzysta z plików cookie. Pozostając na tej stronie, wyrażasz zgodę na korzystanie z plików cookie. <a href="/cookiec">Dowiedz się więcej</a>';
  $settings['popup_agreed']['value'] = 'Zgadzam się';

  return $settings;
}

function cookiec_policy_text_pl($lang) {
  $text = '<h2>Polityka Cookie</h2>

    <p>Serwis nie zbiera w sposób automatyczny żadnych informacji, z wyjątkiem informacji zawartych w plikach cookies.</p>
    <p>Pliki cookies (tzw. „ciasteczka”) stanowią dane informatyczne, w szczególności pliki tekstowe, które przechowywane są w urządzeniu końcowym Użytkownika Serwisu i przeznaczone są do korzystania ze stron internetowych Serwisu. Cookies zazwyczaj zawierają nazwę strony internetowej, z której pochodzą, czas przechowywania ich na urządzeniu końcowym oraz unikalny numer.</p>
    <p>Podmiotem zamieszczającym na urządzeniu końcowym Użytkownika Serwisu pliki cookies oraz uzyskującym do nich dostęp jest operator serwisu.</p>
    <p>Pliki cookies wykorzystywane są w celu:</p>
    <ul>
      <li>dostosowania zawartości stron internetowych Serwisu do preferencji Użytkownika oraz optymalizacji korzystania ze stron internetowych; w szczególności pliki te pozwalają rozpoznać urządzenie Użytkownika Serwisu i odpowiednio wyświetlić stronę internetową, dostosowaną do jego indywidualnych potrzeb;</li>

      <li>tworzenia statystyk, które pomagają zrozumieć, w jaki sposób Użytkownicy Serwisu korzystają ze stron internetowych, co umożliwia ulepszanie ich struktury i zawartości;</li>

      <li>utrzymanie sesji Użytkownika Serwisu (po zalogowaniu), dzięki której Użytkownik nie musi na każdej podstronie Serwisu ponownie wpisywać loginu i hasła;</li>
    </ul>

    <p>W ramach Serwisu stosowane są dwa zasadnicze rodzaje plików cookies: „sesyjne”  (session cookies) oraz „stałe” (persistent cookies). Cookies „sesyjne” są plikami tymczasowymi, które przechowywane są w urządzeniu końcowym Użytkownika do czasu wylogowania, opuszczenia strony internetowej lub wyłączenia oprogramowania (przeglądarki internetowej). „Stałe” pliki cookies przechowywane są w urządzeniu końcowym Użytkownika przez czas określony w parametrach plików cookies lub do czasu ich usunięcia przez Użytkownika.</p>
    <p>W ramach Serwisu stosowane są następujące rodzaje plików cookies:</p>

    <ul>
      <li>„niezbędne” pliki cookies, umożliwiające korzystanie z usług dostępnych w ramach Serwisu, np. uwierzytelniające pliki cookies wykorzystywane do usług wymagających uwierzytelniania w ramach Serwisu;</li>

      <li>pliki cookies służące do zapewnienia bezpieczeństwa, np. wykorzystywane do wykrywania nadużyć w zakresie uwierzytelniania w ramach Serwisu;</li>

      <li>„wydajnościowe” pliki cookies, umożliwiające zbieranie informacji o sposobie korzystania ze stron internetowych Serwisu;</li>

      <li>„funkcjonalne” pliki cookies, umożliwiające „zapamiętanie” wybranych przez Użytkownika ustawień i personalizację interfejsu Użytkownika, np. w zakresie wybranego języka lub regionu, z którego pochodzi Użytkownik, rozmiaru czcionki, wyglądu strony internetowej itp.;</li>

      <li>„reklamowe” pliki cookies, umożliwiające dostarczanie Użytkownikom treści reklamowych bardziej dostosowanych do ich zainteresowań.</li>


    <p>W wielu przypadkach oprogramowanie służące do przeglądania stron internetowych (przeglądarka internetowa) domyślnie dopuszcza przechowywanie plików cookies w urządzeniu końcowym Użytkownika. Użytkownicy Serwisu mogą dokonać w każdym czasie zmiany ustawień dotyczących plików cookies. Ustawienia te mogą zostać zmienione w szczególności w taki sposób, aby blokować automatyczną obsługę plików cookies w ustawieniach przeglądarki internetowej bądź informować o ich każdorazowym zamieszczeniu w urządzeniu Użytkownika Serwisu. Szczegółowe informacje o możliwości i sposobach obsługi plików cookies dostępne są w ustawieniach oprogramowania (przeglądarki internetowej).</p>
    <p>Operator Serwisu informuje, że ograniczenia stosowania plików cookies mogą wpłynąć na niektóre funkcjonalności dostępne na stronach internetowych Serwisu.</p>
    <p>Pliki cookies zamieszczane w urządzeniu końcowym Użytkownika Serwisu i wykorzystywane mogą być również przez współpracujących z operatorem Serwisu reklamodawców oraz partnerów.</p>
    <p>Więcej informacji na temat plików cookies dostępnych jest pod adresem www.wszystkoociasteczkach.pl lub w sekcji „Pomoc” w menu przeglądarki internetowej.</p>
    <hr/>
    <p>Poniższy wzór polityki cookies chroniony jest prawem autorskim, które przysługują IAB Polska. Zaczerpnięte z www.wszystkoociasteczkach.pl</p>';

  return $text;
}
