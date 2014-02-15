website DrupalCamp Wrocław
============================

Strona internetowa  DrupalCamp Wrocław.

Strona konferencji www.drupalcampwroclaw.pl

Zmiany w repo wprowadzamy w branchu "develop", zgodnie z git flow
- https://github.com/nvie/gitflow
- http://nvie.com/posts/a-successful-git-branching-model/

Strona to profil instalacyjny oparty o platformę Drupala.
W pliku /docs/developer-info.txt instrukcja jak zainstalować stronę na serwerze linuksowym, wymagany Drush.
Do katalogu /conf/local skopiuj pliki z /conf/template i zmień w plikach parametry zależnie od ustawień swojego serwera.
Style do szablonu piszemy w plikach scss (SASS http://sass-lang.com/)
Używamy Zen Grids http://zengrids.com/

Jeśli chcesz pomóc w rozwoju strony i otrzymać uprawnienia do repozytorium GIT pisz na adres info@drupalcampwroclaw.pl lub w https://github.com/DrupalCampWroclaw/website/issues

Sprawy organizacyjne konferencji: https://github.com/DrupalCampWroclaw/organizacyjne/issues

Organizatorzy konferencji: https://github.com/DrupalCampWroclaw?tab=members

----------------------------

Jak pracować nad stroną:
- skrypty działają tylko pod systemem Linux
- instalujesz Drush
- pobierasz repo (git clone)
- ustawiasz sobie vhosta na lokalnym komputerze np www.drupalcampwroclaw.local
- dodajesz wpisz w /etc/hosts
- tworzysz bazę danych
- do katalogu /conf/local kopiujesz pliki z /conf/template
- konfigurujesz pliki w /conf/local - podajesz parametry swojego lokalnego srodowiska
- wklepujesz w konsoli komendę do builda jak w https://github.com/DrupalCampWroclaw/website/blob/develop/docs/developer-info.txt (tylko zmieniasz ścieżkę).
