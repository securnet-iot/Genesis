#!/bin/sh

$S32DS_ARM_UTILS_BIN_PATH = $env:ALCON_TOOLS_PATH + "\S32DS_ARM_v2018.R1\utils\msys32\usr\bin"
$S32DS_PPC_UTILS_BIN_PATH = $env:ALCON_TOOLS_PATH + "\S32DS_Power_v2.1\S32DS\build_tools\msys32\usr\bin"
$IMX_UTILS_BIN_PATH = $env:ALCON_TOOLS_PATH + "\S32DS_Power_v2.1\S32DS\build_tools\msys32\usr\bin"
$NATIVE_UTILS_BIN_PATH = $env:ALCON_TOOLS_PATH + "\MSYS2\usr\bin"
$NATIVE_TOOLS_BIN_PATH = $env:ALCON_TOOLS_PATH + "\MSYS2\mingw64\bin"
$TOOL_7ZIP_PATH = "C:\Program Files\7-Zip"

function AlconUtilsPath ( $platform, $package ) {
  $temp_var = 0

  # Remove any existing items with same name from PATH
  $Env:Path = ($Env:path.Split(';') | Where-Object { $_ -ne $S32DS_ARM_UTILS_BIN_PATH }) -join ';'
  $Env:Path = ($Env:path.Split(';') | Where-Object { $_ -ne $S32DS_PPC_UTILS_BIN_PATH }) -join ';'
  $Env:Path = ($Env:path.Split(';') | Where-Object { $_ -ne $IMX_UTILS_BIN_PATH }) -join ';'
  $Env:Path = ($Env:path.Split(';') | Where-Object { $_ -ne $NATIVE_UTILS_BIN_PATH }) -join ';'
  $Env:Path = ($Env:path.Split(';') | Where-Object { $_ -ne $NATIVE_TOOLS_BIN_PATH }) -join ';'

  # Add new item to PATH
  If ($platform -eq "7zip") {
    $Env:Path = ($Env:path.Split(';') | Where-Object { $_ -ne $TOOL_7ZIP_PATH }) -join ';'
    $Env:Path += ";" + $TOOL_7ZIP_PATH
    [Environment]::SetEnvironmentVariable("Path", $env:Path, [System.EnvironmentVariableTarget]::User)
    $temp_var = 2
  }
  ElseIf ( $platform -eq "arm" ) {
    $env:BUILD_SYSTEM = "powershell"
    $Env:Path += ";" + $S32DS_ARM_UTILS_BIN_PATH
  }
  ElseIf ( $platform -eq "ppc" ) {
    $env:BUILD_SYSTEM = "powershell"
    $Env:Path += ";" + $S32DS_PPC_UTILS_BIN_PATH
  }
  ElseIf ( $platform -eq "imx" ) {
    $env:BUILD_SYSTEM = "powershell"
    $Env:Path += ";" + $IMX_UTILS_BIN_PATH
  }
  ElseIf ( $platform -eq "native" ) {
    $env:BUILD_SYSTEM = "powershell"
    $Env:Path += ";" + $NATIVE_UTILS_BIN_PATH + ";" + $NATIVE_TOOLS_BIN_PATH
  }
  Else {
    $temp_var = 1
    Write-Output "`n`r********* Fail: No Platform is supplied *********`n`r"
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

function AlconUtilsPathRemove ( $platform ) {
  $temp_var = 0
  # Remove any existing items with same name from PATH
  if ( $platform -eq "arm" ) {
    $Env:Path = ($Env:path.Split(';') | Where-Object { $_ -ne $S32DS_ARM_UTILS_BIN_PATH }) -join ';'
  }
  ElseIf ( $platform -eq "ppc" ) {
    $Env:Path = ($Env:path.Split(';') | Where-Object { $_ -ne $S32DS_PPC_UTILS_BIN_PATH }) -join ';'
  }
  ElseIf ( $platform -eq "imx" ) {
    $Env:Path = ($Env:path.Split(';') | Where-Object { $_ -ne $IMX_UTILS_BIN_PATH }) -join ';'
  }
  ElseIf ( $platform -eq "native" ) {
    $Env:Path = ($Env:path.Split(';') | Where-Object { $_ -ne $NATIVE_UTILS_BIN_PATH }) -join ';'
    $Env:Path = ($Env:path.Split(';') | Where-Object { $_ -ne $NATIVE_TOOLS_BIN_PATH }) -join ';'
  }
  Else {
    $temp_var = 1
    Write-Output "`n`r********* Fail: No Platform is supplied *********`n`r"
  }

  If ( $temp_var -eq 0 ) {
    Write-Output "Items in PATH Variable"
    Write-Output "----------------------"
    Write-Output $Env:Path.Split(';')
    Write-Output "`n`r********* Pass: Requested platform path removed from PATH variable *********`n`r"
  }
}
