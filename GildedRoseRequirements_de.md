# Anforderungsspezifikation Güldene Rose ("Gilded Rose")

Hallo und willkommen im Team Güldene Rose ("Gilded Rose").

Wie du weißt, sind wir ein kleines
[Lokal](https://wowpedia.fandom.com/wiki/Gilded_Rose) einer namhaften Stadt in
bester Lage, das von einer freundlichen Gastwirtin namens
[Allison](https://wowpedia.fandom.com/wiki/Innkeeper_Allison) geführt wird.

Ausserdem handeln wir mit den allerfeinsten Waren.  Unglücklicherweise nimmt die
Qualität unserer Waren ständig ab während sie sich ihrem
Mindesthaltbarkeitsdatum nähern.

Wir haben ein System installiert, das unsere Bestandslisten aktualisiert.  Es
wurde von einem nüchternen Kerl namens
[Leeroy](https://wowpedia.fandom.com/wiki/Leeroy_Jenkins) entwickelt, der zu
neuen Abenteuern aufgebrochen ist.

Deine Aufgabe ist es, unser System um eine neue Funktionalität zu erweitern,
sodass wir eine neue Kategorie von Artikeln ("items") verkaufen können.

Zunächst eine Einführung in unser System:

- Jeder Artikel ("item") besitzt einen `sellIn`-Wert ("Resthaltbarkeit").  Er
  gibt die Anzahl der Tage an, die uns zum Verkauf einer Ware verbleiben.
- Jeder Artikel besitzt einen `quality`-Wert ("Qualität").  Er gibt an, wie
  wertvoll der Artikel ist.
- Am Ende eines jeden Tages senkt unser System beide Werte für jeden Artikel.

Kling einfach, oder?  Tja, hier wird es interessant:

- Sobald das Mindesthaltbarkeitsdatum überschritten ist, verschlechtert sich
  Qualität doppelt so schnell.
- Die Qualität eines Artikel wird nie negativ.
- Alter Brie ("Aged Brie") wird besser, je älter er wird.
- Die Qualität eines Artikels beträgt nie mehr als 50.
- ["Sulfuras"](https://wowpedia.fandom.com/wiki/Sulfuras,_Hand_of_Ragnaros) ist
  ein legendärer Gegenstand, muss nie verkauft werden und verliert nie an
  Qualität.
- Backstagepässe ("Backstage passes") steigen - wie alter Brie - an Qualität,
  wenn sich ihr Mindesthaltbarkeitsdatum nähert:
    * Ihre Qualität erhöht sich um 2, wenn 10 oder weniger Tage übrig sind, und
      um 3, wenn 5 oder weniger Tage übrig sind.
    * Aber: Nach dem Konzert sinkt die Qualität auf 0.

Wir haben vor kurzem einen Lieferanten für heraufbeschworene Waren unter Vertrag
genommen.  Das erfordert eine Anpassung unseres Systems:

- Heraufbeschworene ("conjured") Waren verlieren ihre Qualität doppelt so
  schnell wie normale.

Du darfst die `updateQuality` Methode beliebig umschreiben und neuen Code
hinzufügen, solange das System weiterhin korrekt arbeitet.

Ändere jedoch nicht die `Item` Klasse oder ihre Eigenschaften.  Sie gehört dem
Kobold in der Ecke, der dich andernfalls "insta-raged" und "one-shotted", da er
nicht an eine gemeinsame Verantwortung für Code glaubt.  (Solltest du die
`updateQuality` Methode oder die Item-Eigenschaften `static` deklarieren wollen,
würden wir dir allerdings den Rücken freihalten.)

Um es noch einmal klarzustellen:  Die Qualität eines Gegenstandes kann nie über
50 steigen.  "Sulfuras" ist allerdings ein legendärer Gegenstand, besitzt als
solcher eine Qualität von 80 und ändert sich nie.
