//
//  ReadMe
//  Text
//  ----------------------------------
//  Developed with embedXcode
//
//  Project 	EMT-rtosSetup
//  Created by 	Rei Vilo on Jun 20, 2015
//  Copyright	(c) Rei Vilo, 2015
//  Licence     CC = BY SA NC
//


rtosSetup() is called before all other tasks

*   Optional declaration
*   Defined in main sketch or in rtosGlobals.h
*   No delay() in rtosSetup()!
*   Tested on MSP432 and CC3200

Output

rtosSetup...done
setup...done
o*o*o*o*o*o*o*o*



In setup(), delay(100); is required to to avoid scrambled Serial.print() output

rtop.doo*o*o*o*o*o*o

