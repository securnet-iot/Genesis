#!/bin/sh

$NATIVE_UTILS_BIN_PATH = $env:GENESIS_TOOLS_PATH + "\msys64\usr\bin"
$NATIVE_TOOLS_BIN_PATH = $NATIVE_UTILS_BIN_PATH
$RASP_UTILS_BIN_PATH = $NATIVE_UTILS_BIN_PATH
$RASP_TOOLS_BIN_PATH = $env:GENESIS_TOOLS_PATH + "\rasp-gcc\bin"
$OPENCV_LIBS_PATH = $env:GENESIS_TOOLS_PATH + "\msys64\mingw64\bin"

function GenesisToolSetPath ( $platform, $package ) {
  $temp_var = 0

  # Remove any existing items with same name from PATH
  $Env:Path = ($Env:path.Split(';') | Where-Object { $_ -ne $NATIVE_UTILS_BIN_PATH }) -join ';'
  $Env:Path = ($Env:path.Split(';') | Where-Object { $_ -ne $NATIVE_TOOLS_BIN_PATH }) -join ';'
  $Env:Path = ($Env:path.Split(';') | Where-Object { $_ -ne $RASP_UTILS_BIN_PATH }) -join ';'
  $Env:Path = ($Env:path.Split(';') | Where-Object { $_ -ne $RASP_TOOLS_BIN_PATH }) -join ';'
  $Env:Path = ($Env:path.Split(';') | Where-Object { $_ -ne $OPENCV_LIBS_PATH }) -join ';'

  If ( $platform -eq "native" ) {
    $env:BUILD_SYSTEM = "powershell"
    $Env:Path += ";" + $NATIVE_UTILS_BIN_PATH + ";" + $NATIVE_TOOLS_BIN_PATH  + ";" + $OPENCV_LIBS_PATH
  }
  ElseIf ( $platform -eq "rasp" ) {
    $env:BUILD_SYSTEM = "powershell"
    $Env:Path += ";" + $RASP_UTILS_BIN_PATH + ";" + $RASP_TOOLS_BIN_PATH
  }
  Else {
    $temp_var = 1
    Write-Output "`n`r********* Fail: Platform not selected *********`n`r"
  }

  If ( $temp_var -eq 0 ) {
    Write-Output "Items in PATH Variable"
    Write-Output "----------------------"
    Write-Output $Env:Path.Split(';')
    Write-Output "`n`r********* Pass: Requested platform path temporarily added to PATH variable *********`r`n"
  }
  ElseIf ( $temp_var -eq 2 ) {
    Write-Output "Items in PATH Variable"
    Write-Output "----------------------"
    Write-Output $Env:Path.Split(';')
    Write-Output "`n`r********* Pass: Requested path permanently added to PATH variable *********`r`n"
  }
}

function GenesisToolSetPathRemove ( $platform ) {
  $temp_var = 0
  # Remove any existing items with same name from PATH
  If ( $platform -eq "native" ) {
    $Env:Path = ($Env:path.Split(';') | Where-Object { $_ -ne $NATIVE_UTILS_BIN_PATH }) -join ';'
    $Env:Path = ($Env:path.Split(';') | Where-Object { $_ -ne $NATIVE_TOOLS_BIN_PATH }) -join ';'
  }
  ElseIf ( $platform -eq "rasp" ) {
    $Env:Path = ($Env:path.Split(';') | Where-Object { $_ -ne $RASP_UTILS_BIN_PATH }) -join ';'
    $Env:Path = ($Env:path.Split(';') | Where-Object { $_ -ne $RASP_TOOLS_BIN_PATH }) -join ';'
  }
  Else {
    $temp_var = 1
    Write-Output "`n`r********* Fail: Platform not selected *********`n`r"
  }

  If ( $temp_var -eq 0 ) {
    Write-Output "Items in PATH Variable"
    Write-Output "----------------------"
    Write-Output $Env:Path.Split(';')
    Write-Output "`n`r********* Pass: Requested platform path removed from PATH variable *********`n`r"
  }
}
