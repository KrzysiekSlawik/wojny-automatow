# wojny-automatow
Gra ascii polegająca na programowaniu armi robotów, której zadaniem jest zniszczenie armi przeciwnika. Oryginalna wersja pozwala na programowanie robotów w autorskim języku (podobnym do maszyny ram), wersja w "wersja lua.zip" pozwala na wykorzystanie lua jako języka programowania robotów.

Obie wersje przewidziane są na linuxa, wymagają ncurses (ale wprowadzając zmiany w bibliotece Display można uzyskać kompatybilność z windows) 

Instrukcja instalacji:
• do instalacji potrzebny jest make i biblioteki ncurses i lua5.3 (projekt
testowany pod systemem ubuntu uruchomienie na innych systemach może
wymagać zmian w pliku display.c)
• będąc w katalogu z plikami źródłowymi należy wywołać polecenie make
◦ dodatkowo w pliku makefile można zmodyfikować niektóre ustawienia, co
ze względów prezentacyjnych jest niezalecane (przykładowe ai napisane
jest pod domyślne ustawienia)
• by uruchomić rozgrywkę:
◦ ustawić map.cfg wedle uznania (zmiana rozmiaru mapy może negatywnie
wpłynąć na zachowanie przykładowego ai)
◦ napisać i podmienić jeden ze skryptów baz jak i dodać ai dla całej reszty
armii lub zostawić przykładowe
◦ uruchomić z terminala ./main
