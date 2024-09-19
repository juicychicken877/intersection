// left road
const int LEFT_RED_LIGHT = 2;
const int LEFT_YELLOW_LIGHT = 3;
const int LEFT_GREEN_LIGHT = 4;

// right road
const int RIGHT_RED_LIGHT = 13;
const int RIGHT_YELLOW_LIGHT = 12;
const int RIGHT_GREEN_LIGHT = 11;

// top road
const int TOP_RED_LIGHT = 5;
const int TOP_YELLOW_LIGHT = 6;
const int TOP_GREEN_LIGHT = 7;

// bottom road
const int BOTTOM_RED_LIGHT = 10;
const int BOTTOM_YELLOW_LIGHT = 9;
const int BOTTOM_GREEN_LIGHT = 8;

const int DELAY_BTWN_LIGHTS = 1000;

class Road {
  private:
    int RED_LIGHT;
    int YELLOW_LIGHT;
    int GREEN_LIGHT;
  public:
    Road(int red, int yellow, int green) {
      RED_LIGHT = red;
      YELLOW_LIGHT = yellow;
      GREEN_LIGHT = green;
    }

    void redLights() {
      digitalWrite(RED_LIGHT, HIGH);
    }

    void redToYellow() {
      digitalWrite(RED_LIGHT, LOW);
      digitalWrite(YELLOW_LIGHT, HIGH);
    }

    void yellowToGreen() {
      digitalWrite(YELLOW_LIGHT, LOW);
      digitalWrite(GREEN_LIGHT, HIGH);
    }

    void greenToYellow() {
      digitalWrite(GREEN_LIGHT, LOW);
      digitalWrite(YELLOW_LIGHT, HIGH);
    }

    void yellowToRed() {
      digitalWrite(YELLOW_LIGHT, LOW);
      digitalWrite(RED_LIGHT, HIGH);
    }
};

// create road objects
Road leftRoad(LEFT_RED_LIGHT, LEFT_YELLOW_LIGHT, LEFT_GREEN_LIGHT);
Road rightRoad(RIGHT_RED_LIGHT, RIGHT_YELLOW_LIGHT, RIGHT_GREEN_LIGHT);
Road topRoad(TOP_RED_LIGHT, TOP_YELLOW_LIGHT, TOP_GREEN_LIGHT);
Road bottomRoad(BOTTOM_RED_LIGHT, BOTTOM_YELLOW_LIGHT, BOTTOM_GREEN_LIGHT);

void setup() {
  // left road
  pinMode(LEFT_RED_LIGHT, OUTPUT);
  pinMode(LEFT_YELLOW_LIGHT, OUTPUT);
  pinMode(LEFT_GREEN_LIGHT, OUTPUT);
  // right road
  pinMode(RIGHT_RED_LIGHT, OUTPUT);
  pinMode(RIGHT_YELLOW_LIGHT, OUTPUT);
  pinMode(RIGHT_GREEN_LIGHT, OUTPUT);
  // top road
  pinMode(TOP_RED_LIGHT, OUTPUT);
  pinMode(TOP_YELLOW_LIGHT, OUTPUT);
  pinMode(TOP_GREEN_LIGHT, OUTPUT);
  // bottom road
  pinMode(BOTTOM_RED_LIGHT, OUTPUT);
  pinMode(BOTTOM_YELLOW_LIGHT, OUTPUT);
  pinMode(BOTTOM_GREEN_LIGHT, OUTPUT);
}

void leftAndRightRoadCycle() {
  // light the left and right road
  leftRoad.redToYellow();
  rightRoad.redToYellow();
  delay(DELAY_BTWN_LIGHTS);
  leftRoad.yellowToGreen();
  rightRoad.yellowToGreen();

  delay(10000);

  // turn off
  leftRoad.greenToYellow();
  rightRoad.greenToYellow();
  delay(DELAY_BTWN_LIGHTS);
  leftRoad.yellowToRed();
  rightRoad.yellowToRed();
}

void topAndBottomRoadCycle() {
  // lights the top and bottom road
  topRoad.redToYellow();
  bottomRoad.redToYellow();
  delay(DELAY_BTWN_LIGHTS);
  topRoad.yellowToGreen();
  bottomRoad.yellowToGreen();

  delay(10000);

  // turn off
  topRoad.greenToYellow();
  bottomRoad.greenToYellow();
  delay(DELAY_BTWN_LIGHTS);
  topRoad.yellowToRed();
  bottomRoad.yellowToRed();
}

void loop() {
  // start with red lights
  leftRoad.redLights();
  rightRoad.redLights();
  topRoad.redLights();
  bottomRoad.redLights();

  delay(3000);

  leftAndRightRoadCycle();

  delay(3000);

  topAndBottomRoadCycle();
}
