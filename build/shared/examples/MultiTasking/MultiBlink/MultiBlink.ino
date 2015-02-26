/*
 * This example shows how to blink multiple LED's at
 * different rates in Energia MT. Each LED Sketch (tab) gets it's
 * own task executing in parallel.
 * The BlueLed tab blinks the blue LED at a rate of 100 ms.
 * The GreenLed tab blinks the green LED at a rate of 500 ms.
 * The RedLed tab blinks the red LED at a rate of 1000ms.
 * Note the names of the setup and loop in these tabs. Energia will look
 * for the keywords with the name setup and loop in it. Each set of matching setup
 * and loop pairs will automatically create a task for that tab. The loop and setup 
 * names will need to be unigue. So for instance, the RedLed tab's setup/loop pair are
 * called setupRedLed() and loopRedLed(). These two functions will now become a task
 * where setupRedLed() will be run ones and loopRedLed() will run repeatedly.
 * 
 */
