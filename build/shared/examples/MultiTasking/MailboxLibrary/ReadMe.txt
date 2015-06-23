//
//  ReadMe
//  Text
//  ----------------------------------
//  Developed with embedXcode
//
//  Project 	EMT-mailbox-template
//  Created by 	Rei Vilo on Jun 16, 2015
//  Copyright 	© 2015 http://embeddedcomputing.weebly.com
//  License     CC = BY SA NC
//

* General paramaters

#define NUMBER 4


* With MODALITY = BIOS_WAIT_FOREVER

Mailbox waits for a free slot before posting a message.

?        Chrono   Action    Message                  Available :        Result
?                           .chrono     .buffer                :
1>        6       TX        6          from 1        1         :        1
*<        100     RX        6          from 1        1         :
2>        102     TX        100        from 2        1         :        1
2>        304     TX        304        from 2        2         :        1
*<        402     RX        100        from 2        1         :
2>        506     TX        506        from 2        2         :        1
1>        508     TX        508        from 1        3         :        1
*<        704     RX        304        from 2        2         :
2>        708     TX        708        from 2        3         :        1
2>        910     TX        910        from 2        4         :        1
*<        1006    RX        506        from 2        3         :
1>        1010    TX        1010       from 1        4         :        1
*<        1308    RX        508        from 1        4         :
2>        1310    TX        1112       from 2        4         :        1
*<        1610    RX        708        from 2        4         :
1>        1612    TX        1512       from 1        4         :        1
*<        1912    RX        910        from 2        4         :
2>        1914    TX        1513       from 2        4         :        1
*<        2214    RX        1010       from 1        4         :
1>        2216    TX        2115       from 1        4         :        1
*<        2516    RX        1112       from 2        4         :
2>        2518    TX        211        from 2        4         :        1


* With MODALITY = BIOS_NO_WAIT

Mailbox doesn't wait for a free slot to post a message.
If no slot are avaialble and thus the message isn't posted, result = false.

?        Chrono   Action    Message                   Available :        Result
?                           .chrono     .buffer                 :
1>        6       TX        6           from 1        1         :        1
*<        100     RX        6           from 1        1         :        1
2>        102     TX        100         from 2        1         :        1
2>        304     TX        304         from 2        2         :        1
*<        402     RX        100         from 2        1         :        1
2>        506     TX        506         from 2        2         :        1
1>        508     TX        508         from 1        3         :        1
*<        704     RX        304         from 2        2         :        1
2>        708     TX        708         from 2        3         :        1
2>        910     TX        910         from 2        4         :        1
*<        1006    RX        506         from 2        3         :        0 <= not posted
1>        1010    TX        1010        from 1        4         :        1
2>        1112    TX        1112        from 2        4         :        0 <= not posted
*<        1308    RX        508         from 1        3         :        0 <= not posted
2>        1314    TX        1314        from 2        4         :        1
1>        1512    TX        1512        from 1        4         :        0 <= not posted
2>        1516    TX        1516        from 2        4         :        0 <= not posted
*<        1610    RX        708         from 2        3         :
2>        1718    TX        1718        from 2        4         :        1

