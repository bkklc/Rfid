#include <SPI.h>      //SPI ve RFID kütüphanelerimizi ekliyoruz
#include <RFID.h>
#include <Keyboard.h>

#define SS_PIN 10
#define RST_PIN 9

RFID rfid(SS_PIN, RST_PIN);


void setup() {
 
  SPI.begin(); //SPI iletişimini başlatıyoruz 
  rfid.init();
  Keyboard.begin(); //Klavye olarak kullanmak için bu özelliği açıyoruz.
  }

void loop() {

  if (rfid.isCard()) {
    if (rfid.readCardSerial()) {
      if (rfid.serNum[0] ==   //Okunan RFID kartının bize özel kart olup olmadığı RFID kart numarasının ilk 5 hanesi ile kontrol ediliyor.
        &&
        rfid.serNum[1] ==   //Buradaki 5 adet sayıyı kendi kartınızın sayıları ile değiştirmeniz gerekecek.
        &&
        rfid.serNum[2] ==  &&
        rfid.serNum[3] ==  &&
        rfid.serNum[4] ==  ) 
        
        Keyboard.press(KEY_RETURN); //Klavyeden ENTER tuşuna basıyoruz
        delay(50);
        Keyboard.releaseAll(); //Basılı olan tuşu geri çekmek için bu fonksiyonu kullanıyoruz. 
        delay(500);
        Keyboard.print("Bilgisayar Şifresi"); //Buraya Bilgisayar şifreniz gelecek
        Keyboard.press(KEY_RETURN); //Klavyeden ENTER tuşuna basıyoruz
        delay(50);
        Keyboard.releaseAll();
         rfid.halt(); 
      }            
  
  }
   else {
   
    if (rfid.readCardSerial()) {
      if (rfid.serNum[0] ==  //Okunan RFID kartının bize özel kart olup olmadığı RFID kart numarasının ilk 5 hanesi ile kontrol ediliyor.        
        &&
        rfid.serNum[1] ==  //Buradaki 5 adet sayıyı kendi kartınızın sayıları ile değiştirmeniz gerekecek.     
        &&
        rfid.serNum[2] ==  &&
        rfid.serNum[3] ==  &&
        rfid.serNum[4] ==    )    
      
        Keyboard.press(KEY_LEFT_ALT); //Klavyeden ALT tuşuna basılıyor
        delay(50);             
        Keyboard.press(KEY_F4); //Klavyeden F4 tuşuna basıyoruz
        delay(50); 
        Keyboard.releaseAll(); //Basılı olan tuşu geri çekmek için bu fonksiyonu kullanıyoruz. 
        Keyboard.press(KEY_RETURN); //Klavyeden ENTER tuşuna basıyoruz
        delay(50);
        Keyboard.releaseAll(); //Basılı olan tuşu geri çekmek için bu fonksiyonu kullanıyoruz. 
        rfid.halt();          
    }
   
    
  }
  rfid.halt();   

}
