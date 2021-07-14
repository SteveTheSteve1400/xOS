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

void InterfaceInit()
{
  //Sets theme to night
  lv_theme_t * th = lv_theme_night_init(65, NULL);
  lv_theme_set_current(th);


  //Set function callbacks for start page buttons
  lv_btn_set_action(start, LV_BTN_ACTION_CLICK, Start);

  //Set function callbacks for main screen buttons
  lv_btn_set_action(sel1, LV_BTN_ACTION_CLICK, Auton);
  lv_btn_set_action(sel5, LV_BTN_ACTION_CLICK, Debug);

  //Set function callbacks for auton 1 buttons
  lv_btn_set_action(autonSel1, LV_BTN_ACTION_CLICK, Auton1);

  //Set function callbacks for auton 2 buttons
  lv_btn_set_action(autonSel2, LV_BTN_ACTION_CLICK, Auton2);

  //Set function callbacks for auton 3 buttons
  lv_btn_set_action(autonSel3, LV_BTN_ACTION_CLICK, Auton3);

  //Style for normal buttons
  lv_style_copy(&buttonREL, &lv_style_plain);
  lv_color_t xBlueRel = LV_COLOR_MAKE(15, 207, 204);
  buttonREL.body.main_color = xBlueRel;
  buttonREL.body.radius = 0;

  lv_style_copy(&buttonPR, &lv_style_plain);
  lv_color_t xBluePR = LV_COLOR_MAKE(15, 103, 207);
  buttonPR.body.main_color = xBluePR;

  lv_btn_set_style(start, LV_BTN_STYLE_REL, &buttonREL);
  lv_btn_set_style(start, LV_BTN_STYLE_PR, &buttonPR);

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
