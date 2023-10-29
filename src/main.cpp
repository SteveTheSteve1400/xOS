//#include "main.h"
#include "display/lv_objx/lv_btn.h"
#include "interface.h"

typedef  FILE * pc_file_t;

static lv_fs_res_t pcfs_open( void * file_p, const char * fn, lv_fs_mode_t mode)
{
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

lv_obj_t * field = lv_img_create(lv_scr_act(), NULL);
//image button
lv_obj_t * btn = lv_imgbtn_create(lv_scr_act(), NULL);
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
 lv_obj_t * createImgBtn(lv_obj_t * parent, lv_coord_t x, lv_coord_t y, const char * title, bool isHidden, bool isRed, bool isBlue)
{
  //title = std::to_string(y).c_str();
  lv_obj_t * btnTemp = lv_imgbtn_create(parent, NULL);
  //lv_obj_align(btn, NULL, align, offsetX, offsetY);
  lv_obj_set_pos(btnTemp, x, y);
  lv_obj_set_hidden(btnTemp, isHidden);

  lv_obj_t * label = lv_label_create(btnTemp, NULL);
  lv_label_set_text(label, title);
  lv_obj_align(label, NULL, LV_ALIGN_IN_LEFT_MID, 0, 5);
  if(isRed){
    lv_imgbtn_set_src(btnTemp, LV_BTN_STATE_INA, "S:/usd/redBtn.bin");
    lv_imgbtn_set_src(btnTemp, LV_BTN_STATE_PR, "S:/usd/redBtn.bin");
    lv_imgbtn_set_src(btnTemp, LV_BTN_STATE_REL, "S:/usd/redBtn.bin");
  }
  else if(isBlue){
    lv_imgbtn_set_src(btnTemp, LV_BTN_STATE_INA, "S:/usd/blueBtn.bin");
    lv_imgbtn_set_src(btnTemp, LV_BTN_STATE_PR, "S:/usd/blueBtn.bin");
    lv_imgbtn_set_src(btnTemp, LV_BTN_STATE_REL, "S:/usd/blueBtn.bin");

  }
  else{
    lv_imgbtn_set_src(btnTemp, LV_BTN_STATE_INA, "S:/usd/skillBtn.bin");
    lv_imgbtn_set_src(btnTemp, LV_BTN_STATE_PR, "S:/usd/skillBtn.bin");
    lv_imgbtn_set_src(btnTemp, LV_BTN_STATE_REL, "S:/usd/skillBtn.bin");
  }
  


  return btnTemp;
}
void initialize() {
  lv_fs_drv_t pcfs_drv;                         /*A driver descriptor*/
  memset(&pcfs_drv, 0, sizeof(lv_fs_drv_t));

  pcfs_drv.file_size = sizeof(pc_file_t);       /*Set up fields...*/
  pcfs_drv.letter = 'S';
  pcfs_drv.open = pcfs_open;
  pcfs_drv.close = pcfs_close;
  pcfs_drv.read = pcfs_read;
  pcfs_drv.seek = pcfs_seek;
  pcfs_drv.tell = pcfs_tell;
  lv_fs_add_drv(&pcfs_drv);

  lv_img_set_src(field, "S:/usd/field.bin");
  lv_obj_t * blueFar = createImgBtn(lv_scr_act(), 37, 14,"Auton", false, false, true);

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
