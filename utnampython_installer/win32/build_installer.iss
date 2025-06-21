[Setup]
AppID={{26d76af6-00e6-440b-b955-6fe1691fa170}}
AppName=utnampython
AppVersion=3.11.9
DefaultDirName={localappdata}\Programs\Utnampython\Utnampython311
DefaultGroupName=utnampython
OutputBaseFilename=utnampython-setup
Compression=lzma
SolidCompression=yes
LicenseFile=files\LICENSE.txt
InfoBeforeFile=files\before_install.txt
InfoAfterFile=files\after_install.txt
; (Your existing setup settings here)
SetupIconFile=files\images\utnampython_icon.ico
WizardImageFile=files\images\utnampython_banner.bmp
WizardSmallImageFile=files\images\utnam_py_small_logo.bmp





[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"
Name: "japanese"; MessagesFile: "compiler:Languages\Japanese.isl"
Name: "korean"; MessagesFile: "compiler:Languages\Korean.isl"
Name: "russian"; MessagesFile: "compiler:Languages\Russian.isl"
Name: "tamil"; MessagesFile: "compiler:Languages\Tamil.isl"

[Files]
; Main executables and DLLs
Source: "files\utnampython.exe";     DestDir: "{app}"; Flags: ignoreversion
Source: "files\python311.dll";       DestDir: "{app}"; Flags: ignoreversion
Source: "files\python3.dll";         DestDir: "{app}"; Flags: ignoreversion
Source: "files\pythonw.exe";         DestDir: "{app}"; Flags: ignoreversion
Source: "files\vcruntime140.dll";    DestDir: "{app}"; Flags: ignoreversion

; Standard Python folders
Source: "files\DLLs\*";    DestDir: "{app}\DLLs";    Flags: ignoreversion recursesubdirs
Source: "files\Include\*"; DestDir: "{app}\Include"; Flags: ignoreversion recursesubdirs
Source: "files\Lib\*";     DestDir: "{app}\Lib";     Flags: ignoreversion recursesubdirs
Source: "files\libs\*";    DestDir: "{app}\libs";    Flags: ignoreversion recursesubdirs

[Icons]
Name: "{group}\utnampython"; Filename: "{app}\utnampython.exe"
Name: "{group}\Uninstall utnampython"; Filename: "{uninstallexe}"

[Run]
Filename: "{app}\utnampython.exe"; Description: "Run utnampython"; Flags: nowait postinstall skipifsilent
[Tasks]
Name: addtopath; Description: "Add utnampython to PATH environment variable"; GroupDescription: "Additional Options:"; Flags: unchecked

[Code]
const
  WM_SETTINGCHANGE = $001A;
  SMTO_ABORTIFHUNG = $0002;

function SendMessageTimeout(hWnd: Integer; Msg: Cardinal; wParam: Integer;
  lParam: Longint; fuFlags: Cardinal; uTimeout: Cardinal; var lpdwResult: Integer): Integer;
  external 'SendMessageTimeoutA@user32.dll stdcall';


procedure AddToUserPath(PathToAdd: string);
var
  currentPath: string;
  newPath: string;
begin
  if not RegQueryStringValue(HKEY_CURRENT_USER, 'Environment', 'Path', currentPath) then
    currentPath := '';

  // Only add if not already present
  if Pos(Lowercase(PathToAdd), Lowercase(currentPath)) = 0 then begin
    if (Length(currentPath) > 0) and (currentPath[Length(currentPath)] <> ';') then
      currentPath := currentPath + ';';
    newPath := currentPath + PathToAdd;

    RegWriteStringValue(HKEY_CURRENT_USER, 'Environment', 'Path', newPath);
  end;
end;

procedure CurStepChanged(CurStep: TSetupStep);
begin
  if (CurStep = ssPostInstall) and IsTaskSelected('addtopath') then begin
    AddToUserPath(ExpandConstant('{app}'));
    MsgBox('Path added to your user environment variable. Please restart your terminal or log off and back on to apply changes.', mbInformation, MB_OK);
  end;
end;
