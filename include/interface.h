#include "main.h"
//#include "display/lvgl.h"
#include "lvglfunctions.h"


#include "display/lv_themes/lv_theme_templ.h"
#include "display/lv_themes/lv_theme_default.h"
#include "display/lv_themes/lv_theme_alien.h"
#include "display/lv_themes/lv_theme_night.h"
#include "display/lv_themes/lv_theme_mono.h"
#include "display/lv_themes/lv_theme_zen.h"
#include <string>


void InterfaceInit()
{
  //Sets theme to night
  lv_theme_t * th = lv_theme_night_init(65, NULL);
  lv_theme_set_current(th);




  //Sets up temperature monitors
  /*
  lv_lmeter_set_range(lmeter, 0, 100);                   /*Set the range
  lv_lmeter_set_value(lmeter, 100);                       /*Set the current value
  lv_lmeter_set_scale(lmeter, 240, 21);                  /*Set the angle and number of lines
  lv_obj_set_size(lmeter, 50, 50);
  lv_obj_align(lmeter, NULL, LV_ALIGN_IN_TOP_LEFT, 25, 5);
  lv_obj_set_hidden(motorBackdrop, true);
  lv_obj_set_size(motorBackdrop, 100, 75);
  lv_obj_set_pos(motorBackdrop, 0, 50);
*/

  //Style for temperature meters



  //Rickroll


  //Sets initial auton page selector button to be inactive. User is immediately taken to that page
  //lv_obj_set_click(autonSel1, false);


  //Sets source for background image




  /*
  // DISPLAY UPDATE LOOP
  while(true){
    // HOME SCREEN ACTIONS
    if(lv_scr_act() == scr0){
      // Set values of battery bars




      pros::delay(100);
    }
  }
  */
}
