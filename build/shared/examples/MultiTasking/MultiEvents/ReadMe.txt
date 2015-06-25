This is an example of multi-events.

Event_Id_01 2000 LED red = R
Event_Id_02 1000 LED green = G
Event_Id_03  500 LED green = G

LED red = R is triggered by Event_Id_01
LED green = G is triggered 
	by (Event_Id_02 AND Event_Id_03) 
	or (Event_Id_02 OR Event_Id_03)

* Events

 123
   3
  23
   3
 123
   3
  23
   3

* NOTE
Only a single Task can pend on an Event object at a time.

* AND
expected = 1R23G32G331R2G332G33
actual   = 1R23G32G331R2G332G33
first time 23G, after 3..2G

* OR
expected = 1R2G3G3G2G3G3G
actual   = 1R2G3G3G2G3G3G
