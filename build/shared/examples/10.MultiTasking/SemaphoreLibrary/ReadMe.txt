This is an example for semaphore.

In this example, the semaphore allows to manage the Serial port and ensure it is used only by the single active task.

Count = 1 is the right value, as there is only one Serial port.

Count = 3 is not recommended. Note the available count between brackets.

Without the semaphore, text is scrambled.


* Without semaphore

3641	: mySemaphore3      3 (-)
3660	: mySemaphore1    1   (-)
3699	: mySemaphore2     2  (-)
3781	: mySemap32  hore1    1   (-)
3813	: mySemaphore3      3 (-)
3862	: mySemaphore2     2  (-)
3904	: mySemaphore1    1   (-)
3944	: mySemaphore2     2  (-)
3985	: mySemaphore3      3 (-)
4022Syrr
)
4107	: mySemaphore2     2  (-)
4147	: mySemaphore1    1   (-)
4157	: mySemaphore3      3 (-)
4189	: mySemaphore2     2  (-)
4269	: mySemaphore1    1 4-: mySemaphore2     2  (-)
4329	: mySemaphore3      3 (-)
4353	: mySemaphore2     2  (-)


* With semaphore and count = 1

0	: mySemaphore1    1   (0)
52	: mySemaphore2     2  (0)
104	: mySemaphore3      3 (0)
156	: mySemaphore1    1   (0)
208	: mySemaphore2     2  (0)
276	: mySemaphore3      3 (0)
328	: mySemaphore1    1   (0)
380	: mySemaphore2     2  (0)
448	: mySemaphore3      3 (0)
500	: mySemaphore1    1   (0)
552	: mySemaphore2     2  (0)
620	: mySemaphore3      3 (0)
672	: mySemaphore1    1   (0)
724	: mySemaphore2     2  (0)
792	: mySemaphore3      3 (0)
844	: mySemaphore1    1   (0)
896	: mySemaphore2     2  (0)
964	: mySemaphore3      3 (0)


* With semaphore and count = 3

0   : mySemaphore1    1   (2)
10  : mySemaphore2     2  (1)
30  : mySemaphore3      3 (0)
92  : mySemaphore2     2  (2)
122 : mySemaphore1    1   (1)
174 : mySemaphore2     2  (2)
202 : mySemaphore3      3 (1)
244 : mySemaphore1    1   (1)
256 : mySemaphore2     2  (1)
338 : mySemaphore2     2  (2)
366 : mySemaphore1    1   (1)
374 : mySemaphore3      3 (0)
420 : mySemaphore2     2  (1)
488 : mySemaphore1    1   (2)
502 : mySemaphore2     2  (1)
546 : mySemaphore3      3 (1)
584 : mySemaphore2     2  (1)
610 : mySemaphore1    1   (1)
666 : mySemaphore2     2  (2)
718 : mySemaphore3      3 (2)
732 : mySemaphore1    1   (1)
748 : mySemaphore2     2  (0)
830 : mySemaphore2     2  (2)
854 : mySemaphore1    1   (1)
890 : mySemaphore3      3 (1)
912 : mySemaphore2     2  (1)
976 : mySemaphore1    1   (2)
994 : mySemaphore2     2  (1)
1062 : mySemaphore3      3 (2)
1076 : mySemaphore2     2  (1)
1098 : mySemaphore1    1   (0)
1158 : mySemaphore2     2  (2)
1220 : mySemaphore1    1   (2)
1234 : mySemaphore3      3 (1)
1240 : mySemaphore2     2  (0)
1322 : mySemaphore2     2  (2)
1342 : mySemaphore1    1   (1)
1404 : mySemaphore2     21(mySemaphore3      3 (1)
