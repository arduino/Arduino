/* START CODE */

struct A_NEW_TYPE {
  int a = 10;
  int b;
  int c;
} foo;

void setup() {

}

void loop() {
 dostuff(&foo);
}

void dostuff (A_NEW_TYPE * bar)
{
  Serial.print("bar.a: ");
  Serial.print(bar->a);
}
/* END CODE */