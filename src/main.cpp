#include "daisysp.h"
#include "daisy_patch.h"

#include <string>

#include "main.h"

using namespace daisy;
using namespace daisysp;

DaisyPatch patch;

const int MENU_SIZE = 7;
std::string menuItems[MENU_SIZE];
int selectedMenuItem = 0;

void SetupMenu() {
  menuItems[0] = "VCO";
  menuItems[1] = "VCA";
  menuItems[2] = "Envelope";
  menuItems[3] = "LFO";
  menuItems[4] = "Logic";
  menuItems[5] = "Delay";
  menuItems[6] = "Reverb";
}

int main(void) {
  patch.Init();
  patch.StartAdc();
  SetupMenu();
  while(true) {
    ProcessControls();
    ProcessOled();
    ProcessOutputs();
  }
}

void FilterMenu() {
  if (selectedMenuItem >= MENU_SIZE) {
    selectedMenuItem = 0;
  } else if (selectedMenuItem < 0) {
    selectedMenuItem = MENU_SIZE - 1;
  }
}

void ProcessControls() {
  patch.UpdateAnalogControls();
  patch.DebounceControls();
  selectedMenuItem += patch.encoder.Increment();
  FilterMenu();
}

void ProcessOutputs() {}

void CreateMenuItem(std::string text, int position, bool highlighted) {
  char* cstr = &text[0];
  patch.display.SetCursor(0, (position-1)*10);
  patch.display.WriteString(cstr, Font_7x10, !highlighted);
}

void ProcessOled() {
  patch.display.Fill(false);

  CreateMenuItem(std::to_string(selectedMenuItem) + " " +
		 menuItems[selectedMenuItem], 1, false);
  CreateMenuItem("Item 2", 2, false);
  CreateMenuItem("Item 3", 3, false);
  CreateMenuItem("Item 4", 4, false);
  CreateMenuItem("Item 5", 5, false);
  CreateMenuItem("Item 6", 6, false);
  
  patch.display.Update();
}
