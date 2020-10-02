#pragma once

#ifndef CASCADE_DROPLETS_DROPLET_MANAGER_H_
#define CASCADE_DROPLETS_DROPLET_MANAGER_H_

#include "droplet.h"

class DropletManager {
private:
  bool split = false;
  DropletState selected_drop = DropletState::kFull;
public:
  /*
   * Toggle droplet split mode.
   */
  void ToggleSplit();

  /*
   * Droplet split mode.
   *
   * @return droplet split mode state
   */
  bool GetSplitMode();

  /*
   * Set the currently selected droplet.
   *
   * @param selected droplet
   */
  void SetSelected(DropletState state);

  /*
   * Get the currently selected droplet.
   *
   * @return selected droplet
   */
  DropletState GetSelected();
};

#endif // CASCADE_DROPLETS_DROPLET_MANAGER_H_
