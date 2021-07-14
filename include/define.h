#include "display/lvgl.h"

#ifndef DEFINE_H
#define DEFINE_H

//Use gif.clean() to remove the gif on reset

lv_obj_t * createBtn(lv_obj_t * parent, lv_coord_t x, lv_coord_t y, lv_coord_t width, lv_coord_t height, const char * title, bool isHidden)
{
  //title = std::to_string(y).c_str();
  lv_obj_t * btnTemp = lv_btn_create(parent, NULL);
  //lv_obj_align(btn, NULL, align, offsetX, offsetY);
  lv_obj_set_pos(btnTemp, x, y);
  lv_obj_set_size(btnTemp, width, height);
  lv_obj_set_hidden(btnTemp, isHidden);

  lv_obj_t * label = lv_label_create(btnTemp, NULL);
  lv_label_set_text(label, title);
  lv_obj_align(label, NULL, LV_ALIGN_IN_TOP_MID, 0, 5);
  return btnTemp;
}

lv_obj_t * createImgBtn(lv_obj_t * parent, lv_coord_t x, lv_coord_t y, const char * title, bool isHidden)
{
  //title = std::to_string(y).c_str();
  lv_obj_t * btnTemp = lv_imgbtn_create(parent, NULL);
  //lv_obj_align(btn, NULL, align, offsetX, offsetY);
  lv_obj_set_pos(btnTemp, x, y);
  lv_obj_set_hidden(btnTemp, isHidden);

  lv_obj_t * label = lv_label_create(btnTemp, NULL);
  lv_label_set_text(label, title);
  lv_obj_align(label, NULL, LV_ALIGN_IN_LEFT_MID, 0, 5);

  lv_imgbtn_set_src(btnTemp, LV_BTN_STATE_REL, "S:/usd/btn.bin");
  lv_imgbtn_set_src(btnTemp, LV_BTN_STATE_PR, "S:/usd/btnPr.bin");
  lv_imgbtn_set_src(btnTemp, LV_BTN_STATE_INA, "S:/usd/btnIna.bin");

  return btnTemp;
}

//Creates the background image
//LV_IMG_DECLARE(bkgSrc);
lv_obj_t * bkg = lv_img_create(lv_scr_act(), NULL);

//Define reset button here

//Rickroll
lv_obj_t * rickRoll = lv_img_create(lv_scr_act(), NULL);

//Screen 1 objects
lv_obj_t * start = createBtn(lv_scr_act(), 200, 150, 100, 50, "Start", false);
lv_obj_t * scr0[1] = {start};

//Screen 2 objects
lv_obj_t * sel1 = createImgBtn(lv_scr_act(), 37, 14,"Auton", true);
lv_obj_t * sel2 = createImgBtn(lv_scr_act(), 37, 89, "Motors", true);
lv_obj_t * sel3 = createImgBtn(lv_scr_act(), 37, 164, "Sensors", true);
lv_obj_t * sel4 = createImgBtn(lv_scr_act(), 250, 14, "Odometry", true);
lv_obj_t * sel5 = createImgBtn(lv_scr_act(), 250, 89, "Debug", true);
lv_obj_t * sel6 = createImgBtn(lv_scr_act(), 250, 164, "Games", true);
lv_obj_t * scr1[6] {sel1, sel2, sel3, sel4, sel5, sel6};

//Screen 3 objects
lv_obj_t * autonSel1 = createBtn(lv_scr_act(), 390, 0, 30, 30, "1", true);
//lv_obj_t * autonScr1[] = {};
lv_obj_t * autonSel2 = createBtn(lv_scr_act(), 420, 0, 30, 30, "2", true);
//lv_obj_t * autonScr2[] = {};
lv_obj_t * autonSel3 = createBtn(lv_scr_act(), 450, 0, 30, 30, "3", true);
//lv_obj_t * autonScrn3[] = {};
lv_obj_t * autonSel[3] = {autonSel1, autonSel2, autonSel3};




#endif
