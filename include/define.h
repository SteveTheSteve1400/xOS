#include "main.h"
#include <map>
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

lv_obj_t * createMeter(lv_obj_t * parent, lv_coord_t x, lv_coord_t y, const char * motorName, const char * motorPort, bool isHidden)
{
  lv_obj_t * motorBackdrop = lv_obj_create(parent, NULL);
  lv_obj_set_size(motorBackdrop, 75, 50);
  lv_obj_set_pos(motorBackdrop, x, y);


  lv_obj_t * lmeter = lv_lmeter_create(motorBackdrop, NULL);
  lv_lmeter_set_range(lmeter, 0, 100);                   /*Set the range*/
  lv_lmeter_set_value(lmeter, 100);                      /*Set the current value*/
  lv_lmeter_set_scale(lmeter, 240, 21);                  /*Set the angle and number of lines*/
  lv_obj_set_size(lmeter, 50, 50);
  lv_obj_align(lmeter, NULL, LV_ALIGN_IN_TOP_LEFT, 25, 5);

  lv_obj_set_hidden(motorBackdrop, isHidden);


  lv_obj_t * label1 = lv_label_create(motorBackdrop, NULL);
  lv_label_set_text(label1, motorName);
  lv_obj_align(label1, NULL, LV_ALIGN_CENTER, 0, 0);

  lv_obj_t * label2 = lv_label_create(motorBackdrop, NULL);
  lv_label_set_text(label2, motorPort);
  lv_obj_align(label2, NULL, LV_ALIGN_IN_BOTTOM_MID, 0, 0);

  return motorBackdrop;
}

//Creates the background image
//LV_IMG_DECLARE(bkgSrc);
lv_obj_t * bkg = lv_img_create(lv_scr_act(), NULL);

//Define reset button here

//Rickroll
lv_obj_t * rickRoll = lv_img_create(lv_scr_act(), NULL);

//Screen 2 objects
lv_obj_t * sel1 = createImgBtn(lv_scr_act(), 37, 14,"Auton", false);
lv_obj_t * sel2 = createImgBtn(lv_scr_act(), 37, 89, "Motors", false);
lv_obj_t * sel3 = createImgBtn(lv_scr_act(), 37, 164, "Sensors", false);
lv_obj_t * sel4 = createImgBtn(lv_scr_act(), 250, 14, "Odometry", false);
lv_obj_t * sel5 = createImgBtn(lv_scr_act(), 250, 89, "Debug", false);
lv_obj_t * sel6 = createImgBtn(lv_scr_act(), 250, 164, "Games", false);
lv_obj_t * scr1[6] {sel1, sel2, sel3, sel4, sel5, sel6};

//Screen 3 objects
lv_obj_t * autonSel1 = createBtn(lv_scr_act(), 390, 0, 30, 30, "1", true);
lv_obj_t * leftWinPoint = createImgBtn(lv_scr_act(), 37, 14, "LeftWP", true);
lv_obj_t * rightWinPoint = createImgBtn(lv_scr_act(), 37, 89, "RightWP", true);
lv_obj_t * leftFullWinPoint = createImgBtn(lv_scr_act(), 37, 164, "Left Full WP", true);
lv_obj_t * rightFullWinPoint = createImgBtn(lv_scr_act(), 250, 89, "Right Full WP", true);
lv_obj_t * autonScr1[] = {leftWinPoint, rightWinPoint, leftFullWinPoint, rightFullWinPoint};
lv_obj_t * autonSel2 = createBtn(lv_scr_act(), 420, 0, 30, 30, "2", true);
lv_obj_t * leftFull = createImgBtn(lv_scr_act(), 37, 14, "Left Full", true);
lv_obj_t * rightFull = createImgBtn(lv_scr_act(), 37, 89, "Right Full", true);
lv_obj_t * autonScr2[] = {leftFull, rightFull};
lv_obj_t * autonSel3 = createBtn(lv_scr_act(), 450, 0, 30, 30, "3", true);
//lv_obj_t * autonScrn3[] = {};
lv_obj_t * autonSel[3] = {autonSel1, autonSel2, autonSel3};

//Screen 4 objects
lv_obj_t * driveFLM = createMeter(lv_scr_act(), 0, 50, "driveFL", "Port: 2", true);
lv_obj_t * motors[1] {driveFLM};


std::map<lv_obj_t*, int> map { {leftWinPoint, 1}, {rightWinPoint, 2}, {leftFullWinPoint, 3}, {rightFullWinPoint, 4}, {leftFull, 5}, {rightFull, 6}};
int auton = 0;



#endif
