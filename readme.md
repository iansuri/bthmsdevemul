#summary Readme notes for the project.

# INTRODUCTION #

Bluetooth for Microsoft Device Emulator enables Bluetooth communication from and to the emulator.

Bluetooth connectivity with the Microsoft Device Emulator has been tested with the following SDKs images:

  * Windows Mobile 5.0 Pocket PC SDK
  * Windows Mobile 5.0 Smartphone SDK
  * Windows Mobile 6 Professional SDK
  * Windows Mobile 6 Standard SDK

# REQUIREMENTS #

Please notice that you MUST have installed ALL the following:

  * Windows XP or Windows Vista 32-bit with the latest service packs.
  * Microsoft Visual Studio 2005 or 2008 with the latest service packs. You Visual Studio installation must include the Smart Device Programmability feature.
  * Windows Mobile 5.0 Pocket PC SDK and/or Windows Mobile 5.0 Smartphone SDK and/or Windows Mobile 6 Professional SDK and/or Windows Mobile 6 Standard SDK emulator images
  * [Microsoft Device Emulator (Recommended: Version 3.0)](http://www.microsoft.com/downloads/details.aspx?familyid=A6F6ADAF-12E3-4B2F-A394-356E2C2FB114&displaylang=en).
  * [Microsoft Remote Tools Framework 1.00](http://www.microsoft.com/downloads/details.aspx?FamilyID=35e9ef0f-833f-4987-9d1f-157a0a6a76e4&DisplayLang=en).

Also you should have available a Bluetooth USB dongle.

# NOTE #

This version of Bluetooth for Microsoft Device Emulator uses [FreeBT](http://freebt.net/) project to access the Bluetooth USB dongle.

# ARCHITECTURE OVERVIEW #

The project consists of the followings components:
  1. Device side
    * [Bluetooth HCI Transport Driver](http://msdn.microsoft.com/en-us/library/ms890918.aspx).
    * [Serial Port Driver](http://msdn.microsoft.com/en-us/library/ms923741.aspx) to abstract the transport driver from  knowing means of communication.
    * Microsoft Remote Tools Framework remote agent.
  1. Desktop side
    * Microsoft Remote Tools Framework desktop plugin.
    * FreeBT USB Driver runtime.
    * FreeBT USB Driver.
    * Connected Bluetooth USB device.

![http://bthmsdevemul.googlecode.com/svn/trunk/site/images/architecture.png](http://bthmsdevemul.googlecode.com/svn/trunk/site/images/architecture.png)

# HARDWARE #

The FreeBT USB Driver is written in accordance with the  Bluetooth USB HCI spec. Any device that follows
the recommendations set down in that spec should be compatible with the FreeBT USB driver.

The fbtusb.inf will, by default, install any USB dongle that identifies itself with Class 0xE0 (Wireless Controller),
SubClass 0x01 (RF Controller) and Protocol 0x01 (Bluetooth programming), in accordance with the USB HCI spec.

Specifically, FreeBT USB has been tested with the following devices:

  * Acer BT-700 (Class 1 device)
  * D-Link DBT-120 (Class 2 device)
  * Any CSR or Silicon Wave-based USB devices

Actually, both of these devices incorporate a CSR BlueCore01 chip, (as do most of the commercially available
Bluetooth dongles at present), which (apart from their amplifiers) makes them identical.


# BLUETOOTH USB DRIVER INSTALLATION #

  1. Open the Windows Device Manager.
  1. In the Device Manager, locate the Bluetooth device to be used as the FreeBT USB device.
  1. Click the right mouse button and select "Update Driver..." in the popup-menu.
  1. Select "No, not this time" and click "Next >".
  1. Select "Install from a list or specific location" and click "Next >".
  1. Select "Don't search. I will choose the driver to install" and click "Next >".
  1. Select the device driver and click the "Have Disk...".
  1. In the Locate File dialog, browse to fbtusb.inf file and click "Next >".
  1. When a "Hardware Installation warning" appears, click "Continue Anyway".
  1. Once the installation has been completed, click "Finish".
  1. The Device Manager should now display "FreeBT USB Driver" in the list of USB controllers.

Please refer to FreeBT documentation for more details.

# INSTALLATION #

  1. Install the Visual Studio 2005 or 2008 with the latest service packs. Your Visual Studio installation should include the Smart Device Programmability feature.
  1. Install the Microsoft Device Emulator. You should have already installed one along with the VS installation. Update it to the [Microsoft Device Emulator 3.0 -- Standalone Release](http://www.microsoft.com/downloads/details.aspx?familyid=A6F6ADAF-12E3-4B2F-A394-356E2C2FB114&displaylang=en).
  1. Install emulator images you need.
  1. You must have an USB Bluetooth dongle available. Plugin in it into an available USB port.
  1. Install the FreeBT USB driver as described in the BLUETOOTH USB DRIVER INSTALLATION section.
  1. Install the [Microsoft Remote Tools Framework 1.00](http://www.microsoft.com/downloads/details.aspx?FamilyID=35e9ef0f-833f-4987-9d1f-157a0a6a76e4&DisplayLang=en).

# GETTING STARTED #

  1. Install the FreeBT USB Driver as described in the BLUETOOTH USB DRIVER INSTALLATION section.
  1. Install all REQUIREMENTS section as described in the INSTALLATION section.
  1. Launch the Remote Tools Framework plugin `BthEmulManager.cetool` from "RTFx Plugin" folder.
  1. Select an emulator image from the list.
  1. Wait for the emulator to be connected.
  1. Select "Bluetooth for Microsoft Device Emulator" node.
  1. If you have a Bluetooth device attached succesfully then the Bluetooth device info (Address, Manufacturer, HCI Version, LMP Version) will be displayed. Bluetooth should now be operational in your emulator. An error code with the description will be displayed otherwise.
  1. To clear the communication log click the right mouse button and select "Clear All".
  1. To copy current device information to the clipboard select "Bluetooth for Microsoft Device Emulator" node, click the right mouse button and select "Copy to Clipboard".
  1. To switch off Bluetooth on the emulator click "Connection" menu item and select "Disconnect from ... emulator".
  1. Microsoft Remote Tools Framework allows you to start two device emulators at the same time. If you have installed two or more FreeBT USB devices click "Windows" menu item and select "Split Windows View". Repeat steps 3-6. You will get two Bluetooth powered emulators are running simultaneously.
  1. It is possible to enable/disable device side logging. If you enable "Device Logging" checkbox then remote logging will be enabled on the emulator. Have a look at `\\Temp` directory on the emulator. There should be created `btd_bthemul_0.txt`, `btd_BthEmulAgent_0.txt`, `btd_bthemulcom_0.txt` files.
  1. It is possible to enable/disable desktop side logging. If you enable "Desktop Logging" checkbox then local logging will be enabled. Have a look at your installation directory. There should be created `BthEmulManager.txt` file.
  1. It is possible to enable/disable communication logging. Communication logging allows to see communication activities between the emulator and the Bluetooth device.

# TROUBLESHOOTING #

Q. I've installed the FreeBT USB Driver but after deploying the emulator Bluetooth is still not working.<br>
A. Install the Microsoft Remote Tools Framework 1.00 if you haven't done it yet. Launch the Remote Tools Framework plugin <code>BthEmulManager.cetool</code> from "RTFx Plugin" folder.<br>
<br>
<br>
Q. I'm trying to connect Pocket PC 2003 SE Emulator but I receive an error all the time: "The device Pocket PC 2003 SE VGA Emulator has a CPU type of ARMV4 and an operating system version of 4.21."<br>
A. Pocket PC 2003 and Smartphone 2003 aren't supported yet.<br>
<br>
<br>
Q. Which Windows Device Manager the README refers to ?<br>
A. Win2K&XP: Start -> Settings -> Control Panel -> System -> Hardware tab -> Device Manager<br>
<br>Vista: Start -> Settings -> Control Panel -> Hardware and Sound -> Device Manager<br>
<br>
<br>
Q. I have started the <code>BthEmulManager.cetool</code> plugin for the first time but nothinng happens. There isn't Bluetooth in the emulator.<br>
A. Try to restart the plugin for the previously chosen emulator. Also go to Settings -> Connections -> Bluetooth -> Mode tab and turn on Bluetooth.<br>
<br>
You may also have problems with the FreeBT USB Driver itself. The driver is still (and will probably remain at this stage) in alpha version.<br>
There are a number of reports saying it has problems. The problems with this driver are the following:<br>
<ol><li>It stops working for no reason.<br>
</li><li>It may miss packets in write/read operations. The problems start when you send large packets very fast. The most probably the problem in an incorrect using of HCI buffers (Read Buffer Size Command, Number Of Completed Packets Event).<br>
</li><li>It isn't stable with some chipset like CSR.</li></ol>

But the driver works quite stable for me at least. I encourage you if you have such problems and have experience in the Windows driver development<br>
try to improve the driver and share your results.<br>
<br>
If something gone wrong after a while with the driver start the Device Manager, select the problem FreeBT USB Driver from the USB device list, click the right mouse button and select "Disable" in the popup-menu. After that click the right mouse button again and select "Enable" in the popup-menu.<br>
<br>
<br>
<h1>THANKS</h1>

Thanks to Antony C. Roberts for his <a href='http://freebt.net/'>FreeBT</a> open source stack. Without it this release would not have been possible.