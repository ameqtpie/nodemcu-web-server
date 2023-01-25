#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

const char*ssid = "Hello_WOrld";
const char*password = "secret123456789";

ESP8266WebServer server(80);

const char htmlPage[]PROGMEM = R"======(
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="UTF-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>HTML Web Page | NodeMCU</title>
    <style>
      body {
        background-color: #000000;
        color: #555;
        font-family: "Segoe UI", Tahoma, Geneva, Verdana, sans-serif;
        font-size: 16px;
        line-height: 1.6em;
        margin: 0;
      }

      .container {
        width: 80%;
        margin: auto;
        overflow: hidden;
      }

      span {
        font-weight: bolder;
      }

      img {
        margin-top: 20px;
        width: 100px;
        border-radius: 50%;
      }
      .rands {
        margin-bottom: 20px;
      }

      #main-header {
        background-color: coral;
        color: #fff;
        text-align: center;
      }

      marquee {
        color: rgb(255, 255, 255);
        margin-top: 25px;
        margin-bottom: 20px;
        font-weight: 700;
        font-size: larger;
      }

      .h1-members {
        margin: 0;
        margin-top: 25px;
        margin-bottom: 25px;
        color: aliceblue;
        transition: font-size 0.15s;
      }

      .h1-members:hover {
        margin: 0;
        margin-top: 25px;
        margin-bottom: 25px;
        font-size: 40px;
        color: aliceblue;
        cursor: pointer;
      }

      .h2-section {
        margin: 0px;
        margin-bottom: 50px;
        color: aliceblue;
        transition: font-size 0.15s;
      }

      .h2-section:hover {
        margin: 0px;
        margin-bottom: 50px;
        font-size: 30px;
        color: aliceblue;
        cursor: pointer;
      }

      #left {
        float: left;
        width: 47%;
        padding: 0 30px;
        box-sizing: border-box;
        text-align: center;
        background-color: rgb(199, 199, 199);
        color: rgb(0, 0, 0);
        border-radius: 10px;
        transition: background-color 0.15s, color 0.15s;
      }

      #left:hover {
        float: left;
        width: 47%;
        padding: 0 30px;
        box-sizing: border-box;
        text-align: center;
        background-color: rgb(87, 87, 87);
        color: rgb(255, 255, 255);
        border-radius: 10px;
        cursor: pointer;
      }

      #right {
        float: right;
        width: 47%;
        padding: 0 30px;
        box-sizing: border-box;
        text-align: center;
        background-color: rgb(199, 199, 199);
        color: rgb(0, 0, 0);
        border-radius: 10px;
      }

      #right:hover {
        float: right;
        width: 47%;
        padding: 0 30px;
        box-sizing: border-box;
        text-align: center;
        background-color: rgb(87, 87, 87);
        color: rgb(255, 255, 255);
        border-radius: 10px;
        cursor: pointer;
      }

      .name {
        margin-top: 20px;
        margin-bottom: 20px;
        font-size: 25px;
      }

      .title {
        margin-top: 10px;
        margin-bottom: 3px;
      }
      .age {
        margin-top: 10px;
        margin-bottom: 3px;
      }

      .address {
        margin-top: 10px;
        margin-bottom: 3px;
      }
      .motto {
        font-weight: 500;
      }

      #members {
        margin-bottom: 20px;
      }

      #main-footer {
        background-color: coral;
        color: #fff;
        text-align: center;
        padding: 20px;
        margin-top: 40px;
      }

      @media (max-width: 600px) {
        .h1-members {
          font-size: 25px;
        }

        .h1-members:hover {
          font-size: 30px;
        }

        marquee {
          font-size: 13px;
        }

        #left {
          width: 100%;
          float: none;
          padding: 20px;
          margin-bottom: 30px;
        }
        #right {
          width: 100%;
          float: none;
          padding: 20px;
        }
      }
      @media (max-width: 800px) {
        marquee {
          font-size: 13px;
        }

        #left {
          width: 100%;
          float: none;
          padding: 20px;
          margin-bottom: 30px;
        }
        #left:hover {
          width: 100%;
          float: none;
          padding: 20px;
          margin-bottom: 30px;
        }

        #right {
          width: 100%;
          float: none;
          padding: 20px;
        }
        #right:hover {
          width: 100%;
          float: none;
          padding: 20px;
        }
      }
    </style>
  </head>
  <body>
    <header id="main-header">
      <div class="container">
        <h1>HTML WEB PAGE</h1>
      </div>
    </header>
    <marquee behavior="alternate" class=""
      >NodeMCU ESP8266 Communication Methods and Protocols</marquee
    >
    <h1 align="center" class="h1-members">GROUP 4 - MEMBERS</h1>
    <h2 align="center" class="h2-section">TO9-A</h2>

    <section id="members">
      <div class="container">
        <section class="sec">
          <div id="left">
            <img
              class="rands"
              src="https://scontent.fceb2-1.fna.fbcdn.net/v/t1.6435-9/80538157_810338939388125_882524700251521024_n.jpg?_nc_cat=101&ccb=1-7&_nc_sid=8bfeb9&_nc_eui2=AeH3tUtKRW-xsheaG_ZLLixOSuMsb7P6_mJK4yxvs_r-YkCWZ4xuyvCTylgNSXZQ3YQqJPl1mdIgKZaZg5fOHWlO&_nc_ohc=nm8TMkV3ajMAX_aPfBk&_nc_ht=scontent.fceb2-1.fna&oh=00_AfCnoWzShq8t-8KqA86KTMPn2xRi1KhTGjTd7Ha6gFsAWQ&oe=63F6FF0F"
            />
            <h1 class="name">Randell Alaya-ay</h1>
            <p class="title"><span>Position: </span>Provider/Financer</p>
            <p class="age"><span>Age: </span>21</p>
            <p class="address"><span>Address: </span>Silay City</p>
            <p class="motto">
              “The most important thing is to enjoy your life – to be happy –
              it’s all that matters.”
            </p>
          </div>
        </section>

        <section class="sec">
          <div id="right">
            <img
              src="https://scontent.fceb2-2.fna.fbcdn.net/v/t39.30808-6/305500345_3184546278487147_2785149971555637908_n.jpg?_nc_cat=100&ccb=1-7&_nc_sid=174925&_nc_eui2=AeF3VVKO3NGOmev1TszNC1xG6BXULClBcY3oFdQsKUFxjRcV7vHt4gTM0jfR4D7KPz7Z1c1XmlBQtUfoZEPb-yeV&_nc_ohc=Sir-JVUQpH0AX_t-9AX&_nc_ht=scontent.fceb2-2.fna&oh=00_AfAo3P_cieS31lpQfSeyvzpBZ1gQFSQjRQ9I6k4b4oEvuw&oe=63D3BAE8"
            />
            <h1 class="name">Stephanie Amenin</h1>
            <p class="title"><span>Position: </span>Secretary</p>
            <p class="age"><span>Age: </span>21</p>
            <p class="address"><span>Address: </span>Pontevedra</p>
            <p class="motto">
              “Vulnerability is not weakness; it’s our most accurate measure of
              courage.”
            </p>
          </div>
        </section>
      </div>
    </section>

    <section id="members">
      <div class="container">
        <section class="sec">
          <div id="left">
            <img
              src="https://scontent.fceb2-1.fna.fbcdn.net/v/t39.30808-6/316671636_3250092555320082_6321925026526892631_n.jpg?_nc_cat=106&ccb=1-7&_nc_sid=09cbfe&_nc_eui2=AeHYYEXPqexvjMsrSH0TJw6IOmjBGibAjdU6aMEaJsCN1RmPc1U5mymYFPvk5OByQxngpwzWeaS9pRbYpigi5MEp&_nc_ohc=vl-TNV0645gAX8xGuFz&_nc_ht=scontent.fceb2-1.fna&oh=00_AfCDlomNcQaBFXO6YIHKQZOCLkaF--r51tYD2EQyXwRq0A&oe=63D445FE"
            />
            <h1 class="name">Angelo Galon</h1>
            <p class="title"><span>Position: </span>Idea Maker</p>
            <p class="age"><span>Age: </span>21</p>
            <p class="address"><span>Address: </span>Cauayan</p>
            <p class="motto">
              “To see what is right and not to do it is want of courage, or of
              principle.”
            </p>
          </div>
        </section>

        <section class="sec">
          <div id="right">
            <img
              src="https://scontent.fceb2-2.fna.fbcdn.net/v/t39.30808-6/309532272_3332904906988786_8034059173288581295_n.jpg?_nc_cat=102&ccb=1-7&_nc_sid=09cbfe&_nc_eui2=AeE7wP8fmc4qxNLHpRn6mvI_MtpbJhNrpAEy2lsmE2ukAQ7uCbmNFsXXE1o0V17Nq4qIi8z6zfWCrAp9DBE70GMT&_nc_ohc=ejncHs9JtE8AX9uLuxW&_nc_ht=scontent.fceb2-2.fna&oh=00_AfDAZPfLddHqGJc7lvQiLxhVymXcLMD9xnN-GewhoFNAiA&oe=63D40CEE"
            />
            <h1 class="name">Rainier Guinsatao</h1>
            <p class="title"><span>Position: </span>Programmer</p>
            <p class="age"><span>Age: </span>21</p>
            <p class="address"><span>Address: </span>Bacolod City</p>
            <p class="motto">
              “It’s how you deal with failure that determines how you achieve
              success.”
            </p>
          </div>
        </section>
      </div>
    </section>

    <section id="members">
      <div class="container">
        <section class="sec">
          <div id="left">
            <img
              src="https://scontent.fceb2-2.fna.fbcdn.net/v/t1.6435-9/88005812_1232680073603520_2451286695098712064_n.jpg?_nc_cat=102&ccb=1-7&_nc_sid=174925&_nc_eui2=AeF1GpxwarOZjxf86DmMpCzqByQNJw5ps2YHJA0nDmmzZuagXLHN_MpDIKaz9rAEcfGcb-_Db7Gi-KH4d8bsFtvO&_nc_ohc=my8R9AW4zo4AX8w-rds&tn=5ryo9uqY0fouNm0I&_nc_ht=scontent.fceb2-2.fna&oh=00_AfC2n8cQj0lrBep60XM91bDRFsCpYFUkWzvLNCLt7NORvw&oe=63F6F859"
            />
            <h1 class="name">Janrey Terencio</h1>
            <p class="title"><span>Position: </span>Designer</p>
            <p class="age"><span>Age: </span>21</p>
            <p class="address"><span>Address: </span>Victorias City</p>
            <p class="motto">
              “Do the best you can until you know better. Then when you know
              better, do better.”
            </p>
          </div>
        </section>

        <section class="sec">
          <div id="right">
            <img
              src="https://scontent.fceb2-2.fna.fbcdn.net/v/t39.30808-6/324413877_867968987658388_5522181963790716355_n.jpg?_nc_cat=102&ccb=1-7&_nc_sid=09cbfe&_nc_eui2=AeFmCUlFt384Lt6iu2t3ypFe4g2BedpsCPXiDYF52mwI9dIOWd-RG05F6w1FoHOmh3GAU6EyexChLk4T1LYwusLi&_nc_ohc=lmakBLjhXYQAX-2tsym&_nc_ht=scontent.fceb2-2.fna&oh=00_AfDUYiDvygw726pUfnPb1ecSqpUsGIWBDkf-B5PoslWDpg&oe=63D50F13"
            />
            <h1 class="name">Jean Amor Valdeviezo</h1>
            <p class="title"><span>Position: </span>Leader</p>
            <p class="age"><span>Age: </span>21</p>
            <p class="address"><span>Address: </span>La Carlota City</p>
            <p class="motto">
              “Trust yourself. Create the kind of self that you will be happy to
              live with all your life.”
            </p>
          </div>
        </section>
      </div>
    </section>

    <footer id="main-footer">Copyright &copy; 2023 GROUP-4 TO9-A</footer>
  </body>
</html>


)======";

void handleRoot(){
  digitalWrite(2,0);
  server.send(200, "text/html",htmlPage);
  digitalWrite(2,1);
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(10);
  pinMode(2, OUTPUT);
  Serial.println();

  Serial.print("Connecting");

  WiFi.begin(ssid, password);

  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("Wi-Fi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);

  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  // put your main code here, to run repeatedly:
  server.handleClient();
}
