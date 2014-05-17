--- Папки ---
Base			- в подпапках Male(мужская) и Female(женская) лежат картнки с изображением одежды.
Images			- изображения манекенов, возможно будут еще и другие картинки.
Libraries		- динамические библиотеки, в часности NetOffice 1.6.0.

--- Файлы ---
!readme.txt		- Вы находитесь здесь.

Clothes.csproj		- файл проекта.
Program.cs

clothes.sdf		- база данных в формате Microsoft SQL Server Compact 4.0

ClothesData.cs		- описание необходимых структур для хранения и передачи данных

DBConnector.cs		- класс DBConnector, реализующий обращение к БД.
EmailSender.cs		- класс EmailSender, реализующий отправку e-mail.

formEmail.cs		- форма диалога отправки e-mail.
formEmail.resx
formEmail.Designer.cs

formMain.cs		- главная форма приложения.
formMain.resx
formMain.Designer.cs

ListViewExtender.cs	- класс ListViewExtender, реализующий расширение функционала базового .net ListView (контрол в ListViewItem)
