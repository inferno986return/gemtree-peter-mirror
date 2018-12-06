# gemtree-peter-mirror
<img src="https://github.com/inferno986return/gemtree-peter-mirror/blob/master/tutorial/petr.gif" width="180" height="180" alt=""/>
A mirror of the Peter programming tool by [Gemtree Software](http://www.breatharian.eu/Petr/en/). To my understanding Peter is similar to [Scratch](https://scratch.mit.edu/) and works by allowing users of different programming skillsets to assemble the program 'like a jigsaw'. Judging by the numerous examples provided, it's safe to say that the program is effectively a 2D and 3D game engine.

<table>
  <tr><td><img src="https://github.com/inferno986return/gemtree-peter-mirror/blob/master/tutorial/preview1.gif" width="180" height="180" alt=""/></td> <td><img src="https://github.com/inferno986return/gemtree-peter-mirror/blob/master/tutorial/preview2.gif" width="180" height="180" alt=""/></td></tr>
</table>

Peter was commercial software until 1st September 2012 when it became freeware and since 1st September 2013 been open-sourced under licensing similar to the BSD License.

Examples of games made using Peter are on the Gemtree website. I recommend trying *Becherbar*, a bar-themed management simulator and *Point236*, a third-person shooter. They are simple games, but enjoyable enough.

The following has been taken from the downloads section of the Peter [website](http://www.breatharian.eu/Petr/en/download.htm#source). The author of the tool is Czech, hence the writing style. The main source code is in the `Peter_v250_src` directory. I have also included the full 70MB *Programming with Peter* tutorial in the `tutorial` directory, however the text is in Czech with no officially provided translation (it seems). Fortunately, as the tutorial is written in HTML it can be translated with Google Translate.

## Source codes

>After a long hesitation, I finally released the source codes of the Peter. Not that I wanted to protect it, but I learned with Peter to program in C++ and it also looks like - the code is very messy and many things are solved completely wrong, I would do it differently today (so that for such a code ashamed). If anyone is interested, here are the codes, but as a source for guidance cannot recommend them.

>Concept of Peter's codes brings certain difficulties. Given that I needed to remove C runtime kernel from the code, I had to do some subterfuges to compiler (MS VC can not compile so much without runtime). The result is that the code is essentially non-transferable under any other compiler than MS VC 6.0 (that means, if you do not spend a lot of days to weeks with remakes). And it requires compilation only under Windows 98 (compiler works badly under XP). Therefore, compilation and completation of the Peter is rather complex. In present time I compile it in Windows 98 under VirtualPC emulator.

>Download source codes of the Peter 2.50 (6 MB) - there are several EXE (subdirectories) in the project:

>* **DataInst** is installer of data files (e.g. installer of sample programs), no longer used today.

>* **DelExe** is utility to delete the installer after uninstalling Peter.

>* **Gener** is utility to complete the Peter's installer. It compiles contents of subdirectories (installation groups) into package: "0"=main program with helps, "1"=applications of the Peter, "2"=item library, "3"=picture library, "4"=sprite library, "5"=sound library, "6"=music library, "7"=other libraries, "8"=sources to generate sprites. Peter.exe file determines date and time of installed files.

>* **HLP** is a help (compiled from RTF files to HLP using HCW compiler).

>* **Loader** is interpreter of a program created in the Peter. Peter adds to it (into EXE header) section ".petprg" which contains edited and executed program. Interpreter at startup compiles it into pseudocode which is executed later - it creates EXECITEM structures, which include addresses of functions to be called fot the entries.

>* **Loader0** is simplified loader. It does not execute the program and serves only as header of the program to enable its distribution in non-executable form (to be smaller file).

>* **Pov2Spr** is converter of pictures to sprites.

>* **Setup** is Peter's installer.

>Compilation requires installation of DirectX SDK 8.1 (but I'm not sure, maybe it is included in the project already enough). Before compilation, you must first run batches "Setup\Res\Source\!Konv.bat", that prepares images for the installer, and "HLP\Source\!Konv.bat", which prepares images for Help. DOS utility alchemy.exe is used and therefore you need enough DOS memory. After that the project can be open in MS VC 6.0. All Release variants need be compiled in all projects. As first you need to compile DelExe project, than you can alphabetically compile from top to bottom (Loader need be compiled before Peter).

>The environment should be Windows 98. When making efforts to run compilation under e.g. Windows XP you will need to run VC in W98 compatibility mode. Internal pictures of the Peter are edited using VC internal editor, Peter is ready to load them (BMP 8 bits RLE format). When editing images the display must not be set to true-color mode, 16-bit color mode must be selected, or editor will damage colors of the picture! Images need be edited under W98 and not under NT and higher, because in the higher systems the images will not be stored compressed and programs will be much bigger. If you edit pictures using another editor, you must delete *.aps files to load new images by the compiler. When you change the version number, fixes should be done in files: Main.h, Setup\Main.h, HLP\Main_cz.rtf, HLP\Main_en.rtf, HLP\Peter_cz.hpj and HLP\Peter_en.hpj. Further guidance to compilation are in !Info.txt.

>Compiled files of Peter 2.50 (3 MB) - thus the output should look like, what "pull" out from Windows 98 in emulator. Then you can continue in your current system.

>Generator of Peter full version 2.50 (323 MB)

>Generator of Peter mini version 2.50 (3,5 MB)

>Generator of Peter Lite version 2.41 (3,6 MB)

>The generators are set of install groups for the Peter installer. The installer will be generated by running Gener.exe program. When generating, files are compressed using the HlpGen program. Date and time of installed files will be set by date and time of the Peter.exe file.

## Licensing
The following is taken from the [About Peter](http://www.breatharian.eu/Petr/en/about.htm) page of the Gemtree website:

> Gemtree Peter was originally licensed application (sold commercially). From 1st September 2012 has been fully released as **FREEWARE**. It may be used for private and commercial purposes. From 1st September 2013 source codes of the Peter where fully released to public use. Peter is offered for use in it's current form as it is, without any further support, development and repair.

> &gt;&gt;&gt; The author takes absolutely no responsibility for damages of any kind resulting from the use of Gemtree Petr application. <<<