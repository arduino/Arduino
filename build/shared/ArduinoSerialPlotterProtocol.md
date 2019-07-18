# SerialPlotter protocol

One message can consist of multiply parts.
One part can consist of one label, one label and a value or only a value.

|  |  | 
| --- | --- |
| End of message symbol | \n |
| Part separator symbols | ' '(space), '\t'(tab), ','(comma) |
| Label-value separator symbol | : |

# Valid messages are

## Labels and value messages:
|                   |    |                   |     |                   |    |
|-------------------|----|-------------------|-----|-------------------|----| 
| Label : Value     |    |                   |     |                   | \n |
| Label 1 : Value 1 | \t | Label 2 : Value 2 |     |                   | \n |
| Label 1 : Value 1 | \t | Label 2 : Value 2 | ... | Label n : Value n | \n |  
		
## Label only messages
|           |    |           |     |          |    |
|-----------|----|-----------|-----|----------|----|
| Label:    |    |           |     |          | \n |
| Label 1 : | \t | Label 2 : |     |          | \n | 
| Label 1 : | \t | Label 2   | ... | Label n: | \n |  

There is a special case, the CSV header style.

|       |    |         |     |         |    |
|-------|----|---------|-----|---------|----|
|Label 1| \t | Label 2 | ... | Label n | \n |  

But in this format, labels consisting of only numbers are not recognised as labels.  
It is safer to just use the normal label only message.

## Value only messages Value
This is not recommended if you using a board with USB to UART converter.
Because when the label is sent, before you had the SerialPlotter opened, then the label/labels get/gets never set.

|         |    |         |     |         |    |
|---------|----|---------|-----|---------|----|
| Value 1 | \t | Value 2 |     |         | \n |  
| Value 1 | \t | Value 2 | ... | Value n | \n |


# Examples
## Single Trace without label

This example plots on line on serial plotter without setting a label

```ino
void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue1 = analogRead(A0);
  
  Serial.println(sensorValue1);

  delay(100);
}
```

The output looks like this
```
10\n
11\n
12\n
13\n
14\n
```
## Single Trace with label

This example sends the label once in the setup routine. Afterwards only the value is send.

```ino
void setup() {
  Serial.begin(9600);
  Serial.println("Label 1:");
}

void loop() {
  int sensorValue1 = analogRead(A0);
  
  Serial.println(sensorValue1);

  delay(100);
}
```

The output looks like this
```
Label 1:\n
10\n
11\n
12\n
13\n
14\n
```

## Single Trace with label send every time

This example sends the label every time together with the value.

```ino
void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue1 = analogRead(A0);
  
  Serial.print("Label 1:"); Serial.println(sensorValue1);

  delay(100);
}
```

The output looks like this
```
Label 1:10\n
Label 1:11\n
Label 1:12\n
Label 1:13\n
Label 1:14\n
```
## Two Traces with label send every time

This example sends two values together with the labels.

```ino
void setup() {
  Serial.begin(9600);
}

float avg = 0;

void loop() {
  int sensorValue1 = analogRead(A0);
  
  // send lable and value seperated by ':'
  Serial.print("Value:"); Serial.print(sensorValue1);


  avg = (avg * 4 + analogRead(A0)) / 5.0;
  // send part devider '\t'
  Serial.print("\t");      
  // send the second lable and value
  Serial.print("AVG5:"); Serial.println(avg);


  delay(100);
}
```

The output looks like this
```
Value:377	AVG5:431.01
Value:338	AVG5:408.81
Value:392	AVG5:395.85
Value:583	AVG5:427.28
Value:221	AVG5:383.42
Value:195	AVG5:343.74
Value:202	AVG5:314.19
Value:209	AVG5:292.15

```

