#!/bin/bash

ALCON_TOOLS_REMOTE_PATH="//10.3.53.71/TeamShare$/Personal/HariKapparapu/NGPV_SDK/Windows/AlconTools"
ALCON_TOOLS_TEST_DEST_PATH=${ALCON_TOOLS_PATH//\\/\/}
LOGFILE=$ALCON_TOOLS_TEST_DEST_PATH/logfile.txt

if [ "$1" = "install" ]
then
  if [ "$2" = "sdk" ]
  then
#    echo -e "Creating desition folder '" $ALCON_TOOLS_TEST_DEST_PATH "'"
#    mkdir -p $ALCON_TOOLS_TEST_DEST_PATH
#    cp $ALCON_TOOLS_REMOTE_PATH/*.pdf $ALCON_TOOLS_TEST_DEST_PATH
#    cp $ALCON_TOOLS_REMOTE_PATH/VersionDetails.txt $ALCON_TOOLS_TEST_DEST_PATH

    echo -e "Installing MSYS2 native tools package"
#    echo -e "   copying..."
#    cp $ALCON_TOOLS_REMOTE_PATH/MSYS2.zip $ALCON_TOOLS_TEST_DEST_PATH
    echo -e "   extracting and installing..."
    7z x $ALCON_TOOLS_TEST_DEST_PATH/MSYS2.zip -o/$ALCON_TOOLS_TEST_DEST_PATH -y > $LOGFILE
#    echo -e "   deleting installer package..."
#    rm $ALCON_TOOLS_TEST_DEST_PATH/MSYS2.zip > $LOGFILE

    echo -e "Installing Lauterbach's' Trace-32 for ARM"
#    echo -e "   copying..."
#    cp $ALCON_TOOLS_REMOTE_PATH/trace32_usb-driver_r_2018_09_000104140.zip $ALCON_TOOLS_TEST_DEST_PATH
#    rm $ALCON_TOOLS_TEST_DEST_PATH/trace32_usb-driver_r_2018_09_000104140.zip > $LOGFILE

#    cp $ALCON_TOOLS_REMOTE_PATH/T32_ARM.7z $ALCON_TOOLS_TEST_DEST_PATH
    echo -e "   extracting and installing..."
    7z x $ALCON_TOOLS_TEST_DEST_PATH/trace32_usb-driver_r_2018_09_000104140.zip -o/$ALCON_TOOLS_TEST_DEST_PATH/trace32_usb-driver -y > $LOGFILE
    7z x $ALCON_TOOLS_TEST_DEST_PATH/T32_ARM.7z -o/$ALCON_TOOLS_TEST_DEST_PATH -y > $LOGFILE
#    echo -e "   deleting installer package..."
#    rm $ALCON_TOOLS_TEST_DEST_PATH/T32_ARM.7z > $LOGFILE

    echo -e "Installing Lauterbach's' Trace-32 for Power PC"
#    echo -e "   copying..."
#    cp $ALCON_TOOLS_REMOTE_PATH/T32_PPC.7z $ALCON_TOOLS_TEST_DEST_PATH
    echo -e "   extracting and installing..."
    7z x $ALCON_TOOLS_TEST_DEST_PATH/T32_PPC.7z -o/$ALCON_TOOLS_TEST_DEST_PATH -y > $LOGFILE
#    echo -e "   deleting installer package..."
#    rm $ALCON_TOOLS_TEST_DEST_PATH/T32_PPC.7z > $LOGFILE

    echo -e "Installing iMXRT tools"
#    echo -e "   copying..."
#    cp $ALCON_TOOLS_REMOTE_PATH/iMXRT.zip $ALCON_TOOLS_TEST_DEST_PATH
    echo -e "   extracting and installing..."
    7z x $ALCON_TOOLS_TEST_DEST_PATH/iMXRT.zip -o/$ALCON_TOOLS_TEST_DEST_PATH -y > $LOGFILE

#    echo -e "Copying S32 Design Studio tools"
#    echo -e "   S32DS for ARM ..."
#    cp $ALCON_TOOLS_REMOTE_PATH/S32DS_ARM*.exe $ALCON_TOOLS_TEST_DEST_PATH
#    cp $ALCON_TOOLS_REMOTE_PATH/S32DS_ARM*.zip $ALCON_TOOLS_TEST_DEST_PATH
#    echo -e "   S32DS for PowerPC ..."
#    cp $ALCON_TOOLS_REMOTE_PATH/S32DS_Power*.exe $ALCON_TOOLS_TEST_DEST_PATH
#    cp $ALCON_TOOLS_REMOTE_PATH/S32DS_PA*.zip $ALCON_TOOLS_TEST_DEST_PATH

    rm $LOGFILE
  elif [ "$2" = "imxrt" ]
  then
    echo -e "Installing iMXRT tools"
    echo -e "   copying..."
    cp $ALCON_TOOLS_REMOTE_PATH/iMXRT.zip $ALCON_TOOLS_TEST_DEST_PATH
    echo -e "   extracting and installing..."
    7z x $ALCON_TOOLS_TEST_DEST_PATH/iMXRT.zip -o/$ALCON_TOOLS_TEST_DEST_PATH -y > $LOGFILE
    rm $LOGFILE
  elif [ "$2" = "startupScripts" ]
  then
    mkdir -p ~/Documents/WindowsPowerShell
    cp WindowsPowerShellScripts/* ~/Documents/WindowsPowerShell/
    echo -e "Close and reopen Visual Code / PowerShell window for changes to take effect"
  fi
elif [ "$1" = "uninstall" ]
then
  if [ "$2" = "sdk" ]
  then
    echo -e "Deleting all installer packages in destination folder"
    rm -r -f $ALCON_TOOLS_TEST_DEST_PATH/*.txt
    rm -r -f $ALCON_TOOLS_TEST_DEST_PATH/*.pdf
    echo -e "   deleting MSYS2 native tools package"
    rm -r -f $ALCON_TOOLS_TEST_DEST_PATH/MSYS2
    rm -r -f $ALCON_TOOLS_TEST_DEST_PATH/MSYS2.zip
    echo -e "   deleting Lauterbach's Trace 32 for ARM"
    rm -r -f $ALCON_TOOLS_TEST_DEST_PATH/trace32_usb-driver
    rm -r -f $ALCON_TOOLS_TEST_DEST_PATH/T32_ARM
    rm -r -f $ALCON_TOOLS_TEST_DEST_PATH/T32_ARM.zip
    echo -e "   deleting Lauterbach's Trace 32 for Power PC"
    rm -r -f $ALCON_TOOLS_TEST_DEST_PATH/T32_PPC
    rm -r -f $ALCON_TOOLS_TEST_DEST_PATH/T32_PPC.zip
  elif [ "$2" = "startupScripts" ]
  then
    rm -r ~/Documents/WindowsPowerShell/*
  fi
fi

echo -e "\n************* COMPLETED *************\n"

count=30
while [ $count -gt 0 ]
do
  printf "\rClosing the window in %d seconds ...        " "$count"
  sleep 1s
  ((count--))
done