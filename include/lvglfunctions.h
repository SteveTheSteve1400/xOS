#include "api.h"
#include "define.h"

//Home screen
static lv_res_t Auton(lv_obj_t * btnTemp)
{
  for(lv_obj_t * obj : scr1)
    lv_obj_set_hidden(obj, true);
  for(lv_obj_t * obj : autonSel)
    lv_obj_set_hidden(obj, false);

  for(lv_obj_t * obj : autonScr1)
    lv_obj_set_hidden(obj, false);

  return LV_RES_OK;
}

static lv_res_t Motors(lv_obj_t * btnTemp)
{
  for(lv_obj_t * obj : scr1)
    lv_obj_set_hidden(obj, true);
  for(lv_obj_t * obj : motors)
  {
    lv_obj_set_hidden(obj, false);
  }

  return LV_RES_OK;
}

static lv_res_t Debug(lv_obj_t * btnTemp)
{
  for(lv_obj_t * obj : scr1)
    lv_obj_set_hidden(obj, true);

  lv_obj_set_hidden(rickRoll, false);

  return LV_RES_OK;
}


//Auton selector
static lv_res_t Auton1(lv_obj_t * btnTemp)
{

  for(lv_obj_t * obj : autonScr2)
    lv_obj_set_hidden(obj, true);
  /*
  for(lv_obj_t * obj : autonScr3)
    lv_obj_set_hidden(obj, true);
  */
  for(lv_obj_t * obj : autonScr1)
    lv_obj_set_hidden(obj, false);


  for(lv_obj_t * obj : autonSel)
    lv_btn_set_state(obj, LV_BTN_STATE_REL);
  lv_btn_set_state(autonSel1, LV_BTN_STATE_INA);

  return LV_RES_OK;
}

static lv_res_t Auton2(lv_obj_t * btnTemp)
{
  for(lv_obj_t * obj : autonScr1)
    lv_obj_set_hidden(obj, true);
  /*
  for(lv_obj_t * obj : autonScr3)
    lv_obj_set_hidden(obj, true);
  */
  for(lv_obj_t * obj : autonScr2)
    lv_obj_set_hidden(obj, false);


  for(lv_obj_t * obj : autonSel)
    lv_btn_set_state(obj, LV_BTN_STATE_REL);
  lv_btn_set_state(autonSel2, LV_BTN_STATE_INA);

  return LV_RES_OK;
}

static lv_res_t Auton3(lv_obj_t * btnTemp)
{
  /*
  for(lv_obj_t * obj : autonScr1)
    lv_obj_set_hidden(obj, true);
  for(lv_obj_t * obj : autonScr2)
    lv_obj_set_hidden(obj, true);

  for(lv_obj_t * obj : autonScr3)
    lv_obj_set_hidden(obj, false);
*/

  for(lv_obj_t * obj : autonSel)
    lv_btn_set_state(obj, LV_BTN_STATE_REL);
  lv_btn_set_state(autonSel3, LV_BTN_STATE_INA);

  return LV_RES_OK;
}

static lv_res_t AutonNumber(lv_obj_t * btnTemp)
{
  auton = map[btnTemp];

  return LV_RES_OK;
}
