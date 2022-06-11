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

lv_style_t buttonREL;
lv_style_t buttonPR;
lv_style_t imgBtn;
lv_style_t meter;

void InterfaceInit()
{
  //Sets theme to night
  lv_theme_t * th = lv_theme_night_init(65, NULL);
  lv_theme_set_current(th);



  //Set function callbacks for main screen buttons
  lv_btn_set_action(sel1, LV_BTN_ACTION_CLICK, Auton);
  lv_btn_set_action(sel2, LV_BTN_ACTION_CLICK, Motors);
  lv_btn_set_action(sel5, LV_BTN_ACTION_CLICK, Debug);

  //Set function callbacks for auton 1 buttons
  lv_btn_set_action(autonSel1, LV_BTN_ACTION_CLICK, Auton1);
  for(auto &b : autonScr1)
    lv_btn_set_action(b, LV_BTN_ACTION_CLICK, AutonNumber);

  //Set function callbacks for auton 2 buttons
  lv_btn_set_action(autonSel2, LV_BTN_ACTION_CLICK, Auton2);
  for(auto &b : autonScr2)
    lv_btn_set_action(b, LV_BTN_ACTION_CLICK, AutonNumber);

  //Set function callbacks for auton 3 buttons
  lv_btn_set_action(autonSel3, LV_BTN_ACTION_CLICK, Auton3);


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
  lv_style_copy(&meter, &lv_style_plain);
  meter.line.color = LV_COLOR_BLACK;
  meter.line.width = 15;
  meter.body.main_color = LV_COLOR_RED;
  meter.body.grad_color = LV_COLOR_BLUE;

  lv_lmeter_set_style(driveFLM, &meter);


  //Rickroll
  lv_img_set_src(rickRoll, "S:/usd/rickRoll.bin");
  lv_obj_set_hidden(rickRoll, true);


  //Sets initial auton page selector button to be inactive. User is immediately taken to that page
  //lv_obj_set_click(autonSel1, false);
  lv_btn_set_state(autonSel1, LV_BTN_STATE_INA);

  //Sets source for background image
  lv_img_set_src(bkg, "S:/usd/bkg2.bin");





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
