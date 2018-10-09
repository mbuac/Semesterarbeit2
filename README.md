# Semesterarbeit2
C++_Programmieren_2, Qt Game
Merve Buacan
7329163


Ziel des Aufgabenteils ist die Programmierung und Gestaltung eines graphischen Spiels unter Verwendung von C++ und QT. 

Der Spieler / die Spielerin soll eine kleine geometrische Figur mittels der Pfeiltasten rechts entlang einer Line am unteren Ende des Spielfeldes steuern können. Von der oberen Spielfeldkante treten „Gegenstände“ ins Spiel ein, die sich zum unteren Ende des Spielfelds bewegen. Ziel des Spiels ist das Ausweichen vor den fallenden Gegenständen und dadurch das möglichst lange „Überleben“. 


Funktionen des Qt Game: 

1. Ein Button „Start“ bzw. „Pause“ startet bzw. stoppt das Spiel. Vorzugsweise wechselt ein Button die Beschriftung. 

2. Am unteren Rand einer Zeichenfläche (~Spielfeld) lässt sich – mit Hilfe der Pfeiltasten – ein schraffiertes Quadrat nach links/rechts steuern. Dieses repräsentiert den „Avatar“ des Spielers.

3. Ein Button „Speichern“ sichert den Zustand des Spiels und seiner Objekte in ein „Savegame“.

4. Ein Button „Laden“ lädt die Informationen aus dem „Savegame“ und stellt den zuletzt gespeicherten Zustand wieder her. 

5. Links oben zeigt eine Zahl einen Punkte-Counter an. Er steigt gleichmäßig und regelmäßig an.

6. Rechts oben zeigen drei ausgefüllte geometrische Formen (z.B. Kreise oder Herzen) die drei Leben des Spielers an.

7. Das Spiel generiert Objekte, die das Spielfeld am oberen Rand betreten und sich zum unteren Rand bewegen. Wenn Sie diesen überschreiten, werden die Objekte aus dem Spiel entfernt. (ggf. Stufe II beachten!)

