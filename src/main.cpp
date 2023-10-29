//#include "main.h"
#include "display/lv_core/lv_obj.h"
#include "display/lv_objx/lv_btn.h"
#include "interface.h"

typedef  FILE * pc_file_t;
int autonFunc = 0;
lv_obj_t * autonCurrent = lv_label_create(lv_scr_act(), NULL);
lv_obj_t * field = lv_img_create(lv_scr_act(), NULL);
lv_obj_t * dropdown = lv_ddlist_create(lv_scr_act(), NULL);
static lv_fs_res_t pcfs_open( void * file_p, const char * fn, lv_fs_mode_t mode){
    errno = 0;
    const char * flags = "";
    if(mode == LV_FS_MODE_WR) flags = "wb";
    else if(mode == LV_FS_MODE_RD) flags = "rb";
    else if(mode == (LV_FS_MODE_WR | LV_FS_MODE_RD)) flags = "a+";

    char buf[256];
    sprintf(buf, "/%s", fn);
    pc_file_t f = fopen(buf, flags);

    if(f == NULL)
      return LV_FS_RES_UNKNOWN;
    else {
      fseek(f, 0, SEEK_SET);
      pc_file_t * fp = (pc_file_t *)file_p;
      *fp = f;
    }

    return LV_FS_RES_OK;
}

static lv_fs_res_t pcfs_close( void * file_p)
{
    pc_file_t * fp = (pc_file_t *)file_p;
    fclose(*fp);
    return LV_FS_RES_OK;
}

static lv_fs_res_t pcfs_read( void * file_p, void * buf, uint32_t btr, uint32_t * br)
{
    pc_file_t * fp =  (pc_file_t *)file_p;
    *br = fread(buf, 1, btr, *fp);
    return LV_FS_RES_OK;
}

static lv_fs_res_t pcfs_seek( void * file_p, uint32_t pos)
{
    pc_file_t * fp = (pc_file_t *)file_p;
    fseek(*fp, pos, SEEK_SET);
    return LV_FS_RES_OK;
}

static lv_fs_res_t pcfs_tell( void * file_p, uint32_t * pos_p)
{
    pc_file_t * fp =  (pc_file_t *)file_p;
    *pos_p = ftell(*fp);
    return LV_FS_RES_OK;
}
lv_res_t btn_click_action(lv_obj_t * btn){
  lv_obj_set_auto_realign(autonCurrent, true);

  uint8_t id = lv_obj_get_free_num(btn); //id usefull when there are multiple buttons
	if(id == 0){
		autonFunc = 0;
		lv_obj_align(autonCurrent, NULL, LV_ALIGN_IN_RIGHT_MID ,-30,0);
		lv_label_set_text(autonCurrent, "Far Red");
    lv_ddlist_set_options(dropdown, "Winpoint\n"
                                      "Match");
  }
	else if(id == 1){
		autonFunc = 1;
    lv_obj_align(autonCurrent, NULL,  LV_ALIGN_IN_RIGHT_MID,-30,0);
		lv_label_set_text(autonCurrent, "Far Blue");
    lv_ddlist_set_options(dropdown, "Winpoint\n"
                                    "Match");
	}
	else if(id == 2){

		autonFunc = 2;
    lv_obj_align(autonCurrent, NULL,  LV_ALIGN_IN_RIGHT_MID,-30,0);
    lv_label_set_text(autonCurrent, "Close Blue");
    lv_ddlist_set_options(dropdown, "Winpoint\n"
                                    "Match");
	}
	else if(id == 3){
		//lv_obj_del(autonCurrent);
		autonFunc = 3;
    lv_obj_align(autonCurrent, NULL,  LV_ALIGN_IN_RIGHT_MID,-30,0);
		lv_label_set_text(autonCurrent, "Close Red");
    lv_ddlist_set_options(dropdown, "Winpoint\n"
                                    "Match\n"
                                    "Skills");
	}
    return LV_RES_OK;
}

//image button

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
 lv_obj_t * createImgBtn(lv_obj_t * parent, lv_coord_t x, lv_coord_t y, const char * title, bool isHidden, bool isRed, bool isBlue, bool close)
{
  //title = std::to_string(y).c_str();
  lv_obj_t * btnTemp = lv_imgbtn_create(parent, NULL);
  //lv_obj_align(btn, NULL, align, offsetX, offsetY);
  lv_obj_set_pos(btnTemp, x, y);
  lv_obj_set_hidden(btnTemp, isHidden);
  lv_btn_set_action(btnTemp, LV_BTN_ACTION_CLICK, btn_click_action);
  if(isRed && close){
    lv_imgbtn_set_src(btnTemp, LV_BTN_STATE_INA, "S:/usd/redClose.bin");
    lv_imgbtn_set_src(btnTemp, LV_BTN_STATE_PR, "S:/usd/redClose.bin");
    lv_imgbtn_set_src(btnTemp, LV_BTN_STATE_REL, "S:/usd/redClose.bin");
  }
  else if(isBlue && close){
    lv_imgbtn_set_src(btnTemp, LV_BTN_STATE_INA, "S:/usd/blueClose.bin");
    lv_imgbtn_set_src(btnTemp, LV_BTN_STATE_PR, "S:/usd/blueClose.bin");
    lv_imgbtn_set_src(btnTemp, LV_BTN_STATE_REL, "S:/usd/blueClose.bin");

  }
  else if(isRed && !close){
    lv_imgbtn_set_src(btnTemp, LV_BTN_STATE_INA, "S:/usd/redFar.bin");
    lv_imgbtn_set_src(btnTemp, LV_BTN_STATE_PR, "S:/usd/redFar.bin");
    lv_imgbtn_set_src(btnTemp, LV_BTN_STATE_REL, "S:/usd/redFar.bin");
  }
  else if(isBlue && !close){
    lv_imgbtn_set_src(btnTemp, LV_BTN_STATE_INA, "S:/usd/blueFar.bin");
    lv_imgbtn_set_src(btnTemp, LV_BTN_STATE_PR, "S:/usd/blueFar.bin");
    lv_imgbtn_set_src(btnTemp, LV_BTN_STATE_REL, "S:/usd/blueFar.bin");

  }
  else{
    lv_imgbtn_set_src(btnTemp, LV_BTN_STATE_INA, "S:/usd/skills.bin");
    lv_imgbtn_set_src(btnTemp, LV_BTN_STATE_PR, "S:/usd/skills.bin");
    lv_imgbtn_set_src(btnTemp, LV_BTN_STATE_REL, "S:/usd/skills.bin");
  }
  


  return btnTemp;
}
void initialize() {


  lv_obj_align(dropdown, NULL, LV_ALIGN_IN_TOP_RIGHT, 0, 10);
  lv_fs_drv_t pcfs_drv;                         /*A driver descriptor*/
  memset(&pcfs_drv, 0, sizeof(lv_fs_drv_t));
  lv_label_set_text(autonCurrent, "");
  pcfs_drv.file_size = sizeof(pc_file_t);       /*Set up fields...*/
  pcfs_drv.letter = 'S';
  pcfs_drv.open = pcfs_open;
  pcfs_drv.close = pcfs_close;
  pcfs_drv.read = pcfs_read;
  pcfs_drv.seek = pcfs_seek;
  pcfs_drv.tell = pcfs_tell;
  lv_fs_add_drv(&pcfs_drv);

  lv_img_set_src(field, "S:/usd/field.bin");
  lv_obj_t * redFar = createImgBtn(lv_scr_act(), 165, 160,"Auton", false, true, false, false);
  lv_obj_set_free_num(redFar, 0);
  lv_obj_t * blueFar = createImgBtn(lv_scr_act(), 5, 5,"Auton", false, false, true, false);
  lv_obj_set_free_num(blueFar, 1);
  lv_obj_t * blueClose = createImgBtn(lv_scr_act(), 165, 5,"Auton", false, false, true, true);
  lv_obj_set_free_num(blueClose, 2);
  lv_obj_t * redClose = createImgBtn(lv_scr_act(), 5, 160,"Auton", false, true, false, true);
  lv_obj_set_free_num(redClose, 3);
  //lv_obj_t * skills = createImgBtn(lv_scr_act(), 84, 85,"Auton", false, false, false, false);
  //lv_obj_set_free_num(skills, 4);
  

	//pros::Task interface_task(InterfaceInit, 0, TASK_PRIORITY_DEFAULT);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
}
