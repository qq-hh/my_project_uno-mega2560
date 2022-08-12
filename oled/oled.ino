#include <Wire.h>
#include <U8g2lib.h>
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE | U8G_I2C_OPT_DEV_0);    // I2C / TWI


//const   uint8_t bitmap_z []   U8G_PROGMEM  = {
//  0x00, 0x00, 0x01, 0x80, 0x03, 0x80, 0x3F, 0xBC, 0x7F, 0xBE, 0x73, 0xCE, 0x63, 0xCE, 0x63, 0xCE,
//  0x63, 0xCE, 0x7B, 0x9E, 0x7F, 0xBE, 0x3F, 0xBC, 0x1F, 0xB8, 0x03, 0x80, 0x03, 0x80, 0x01, 0x80
//};
//const   uint8_t bitmap_w []   U8G_PROGMEM  = {
//  0x00, 0x00, 0x07, 0xC0, 0x3F, 0xD8, 0x7C, 0x7E, 0x7F, 0xFE, 0x00, 0x00, 0x1C, 0x3C, 0x1C, 0x38,
//  0x0E, 0x70, 0x0F, 0xF0, 0x07, 0xA0, 0x0B, 0xE0, 0x3D, 0xFC, 0x7E, 0xFE, 0x7C, 0x3E, 0x30, 0x00
//};
//const   uint8_t bitmap_z []   U8G_PROGMEM  = {
//0x20,0x10,0x08,0xFC,0x23,0x10,0x88,0x67,0x04,0xF4,0x04,0x24,0x54,0x8C,0x00,0x00,
//0x40,0x30,0x00,0x77,0x80,0x81,0x88,0xB2,0x84,0x83,0x80,0xE0,0x00,0x11,0x60,0x00/*"您",0*/
//};
//const   uint8_t bitmap_w []   U8G_PROGMEM  = {
//0x10,0x10,0xF0,0x1F,0x10,0xF0,0x00,0x80,0x82,0x82,0xE2,0x92,0x8A,0x86,0x80,0x00,
//0x40,0x22,0x15,0x08,0x16,0x61,0x00,0x00,0x40,0x80,0x7F,0x00,0x00,0x00,0x00,0x00/*"好",1*/
//};
//void draw(void) {
//  //u8g.setFont(u8g_font_unifont);
//  //u8g.drawStr( 0, 22, "Hello World!");
//  u8g.setColorIndex(1);
//  u8g.drawBitmapP ( 0 , 0 , 2 , 16 , bitmap_z);
//  u8g.drawBitmapP ( 17 , 0 , 2 , 16 , bitmap_w ); 
//}
//
//void setup(void) {
//
//}
//
//void loop(void) {
//
//  // picture loop
//
//  u8g.firstPage();
//
//  do {
//
//    draw();
//
//  } while ( u8g.nextPage() );
//
//  // rebuild the picture after some delay
//
//  delay(50);
//
//}

void setup(void) {
  u8g2.begin();
  u8g2.enableUTF8Print();//显示中文时需要写此句，否则不需要
}
 
void loop(void) {
  //显示字符串
  u8g2.clearBuffer(); //清除缓冲区
  u8g2.setFont(u8g2_font_6x13_tf); //设置字体类型，更改字体大小请参考
  //【u8g2库字体问题：修改字体+中文字体支持-哔哩哔哩】 https://b23.tv/cEVYCvb
  u8g2.drawStr(0,10,"Hello World!");//方式1，在坐标0 10 处显示字符串
  u8g2.setCursor(0, 40);//方式2，设置光标到达0 40位置
  u8g2.print("Hello World!");//在光标处打印字符串
  u8g2.sendBuffer(); //显示缓冲区的内容
  delay(1000); 
  
  //显示整形、浮点型
  int int_num=15;//要显示的整形变量
  float float_num=15.156;//要显示的浮点型变量，只能显示小数点后2位，四舍五入原则
  u8g2.clearBuffer(); //清除缓冲区
  u8g2.setFont(u8g2_font_6x13_tf); //设置字体类型，更改字体大小请参考
  //【u8g2库字体问题：修改字体+中文字体支持-哔哩哔哩】 https://b23.tv/cEVYCvb
  u8g2.setCursor(0, 10);//设置光标到达0 10位置
  u8g2.print(int_num);//打印数字
  u8g2.setCursor(0, 40);//设置光标到达0 40位置
  u8g2.print(float_num);//打印数字
  u8g2.sendBuffer();//显示缓冲区的内容
  delay(1000);  
  
  //显示中文
  u8g2.clearBuffer(); //清除缓冲区
  u8g2.setFont(u8g2_font_unifont_t_chinese2);//设置字体类型，更改字体大小请参考
  //【u8g2库字体问题：修改字体+中文字体支持-哔哩哔哩】 https://b23.tv/cEVYCvb
  u8g2.setFontDirection(0);//设置字体方向
  u8g2.setCursor(0, 15);//设置光标到达0 15位置
  u8g2.print("Hello World!");//打印字符
  u8g2.setCursor(0, 40);//设置光标到达0 40位置
  u8g2.print("你好世界");    //显示中文
  u8g2.sendBuffer();//显示缓冲区的内容
  delay(1000);
}
