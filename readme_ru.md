﻿#summary Readme notes for the project.

# ВСТУПЛЕНИЕ #

Bluetooth для Microsoft Device Emulator добавляет поддержку Bluetooth в эмулятор.

Bluetooth был проверен со следующими образами операционных систем (ОС):

  * Windows Mobile 5.0 Pocket PC SDK
  * Windows Mobile 5.0 Smartphone SDK
  * Windows Mobile 6 Professional SDK
  * Windows Mobile 6 Standard SDK

# ТРЕБОВАНИЯ #

Пожалуйста обратите внимание, что ВСЕ ниже перечисленное ДОЛЖНО БЫТЬ установлено:

  * Windows XP или Windows Vista 32-bit с последними пакетами обновлений.
  * Microsoft Visual Studio 2005 или 2008 с последними пакетами обновлений. Ваша Visual Studio инсталяция должна включать Smart Device Programmability функциональность.
  * Windows Mobile 5.0 Pocket PC SDK и/или Windows Mobile 5.0 Smartphone SDK и/или Windows Mobile 6 Professional SDK и/или Windows Mobile 6 Standard SDK образы ОС
  * [Microsoft Device Emulator (Рекомендована: Версия 3.0)](http://www.microsoft.com/downloads/details.aspx?familyid=A6F6ADAF-12E3-4B2F-A394-356E2C2FB114&displaylang=en).
  * [Microsoft Remote Tools Framework 1.00](http://www.microsoft.com/downloads/details.aspx?FamilyID=35e9ef0f-833f-4987-9d1f-157a0a6a76e4&DisplayLang=en).

Также у вас должно быть свободное Bluetooth USB устройство.

# ВНИМАНИЕ #

Эта версия Bluetooth для Microsoft Device Emulator использует FreeBT проект [FreeBT](http://freebt.net/) для доступа к Bluetooth USB устройству.

# ОБЗОР АРХИТЕКТУРЫ #

Проект состоит из следующих компонентов:
  1. На стороне эмулятора
    * [Bluetooth HCI транспортный драйвер](http://msdn.microsoft.com/en-us/library/ms890918.aspx).
    * [Драйвер последовательного порта](http://msdn.microsoft.com/en-us/library/ms923741.aspx) для абстрагирования транспортного драйвера от знания конкретного средства связи.
    * Microsoft Remote Tools Framework удаленный агент.
  1. На стороне ПК
    * Microsoft Remote Tools Framework ПК плагин.
    * FreeBT USB библиотека времени выполнения.
    * FreeBT USB драйвер.
    * Подключенное Bluetooth USB устройство.

![http://bthmsdevemul.googlecode.com/svn/trunk/site/images/architecture.png](http://bthmsdevemul.googlecode.com/svn/trunk/site/images/architecture.png)

# АППАРАТНОЕ ОБЕСПЕЧЕНИЕ #

FreeBT USB драйвер написан в соответствие со Bluetooth USB HCI спецификацией. Любое устройство, которое следует рекомендациям этой спецификации должно быть совместимым с FreeBT USB драйвером.

fbtusb.inf по умолчанию устанавливается для любого USB устройства, которое идентифицирует себя как Класс 0xE0 (Беспроводное устройсво), Подкласс 0x01 (Высоко частотное устройство) и Протокол 0x01 (Bluetooth).

FreeBT USB драйвер быть протестирован со следующими устройствами:

  * Acer BT-700 (Класс 1)
  * D-Link DBT-120 (Класс 2)
  * Любые CSR или Silicon Wave USB устройства

В настоящее время, оба выше перечисленные устройства построены на базе CSR BlueCore01 чипа (как и большинство Bluetooth устройств на данный момент), что (исключая их усилители сигнала) делает их идентичными.


# УСТАНОВКА BLUETOOTH USB ДРАЙВЕРА #

  1. Откройте Диспетчер устройств.
  1. В Диспетчере устройств выберите Bluetooth устройство, которое должно быть использовано как FreeBT USB.
  1. Нажмите правую кнопку мыши и выберите "Обновить драйвер..." из всплывающего меню.
  1. Выберите "Нет, не в этот раз" и нажмите "Далее >".
  1. Выберите "Установка из указанного места" и нажмите "Далее >".
  1. Выберите "Не выполнять поиск. Я сам выберу нужный драйвер" и нажмите "Далее >".
  1. Нажмите "Установить с диска...".
  1. Укажите расположение файла fbtusb.inf и нажмите "Далее >".
  1. При появление предупреждения о несовместимости выберите "Все равно продолжить".
  1. Когда установка будет закончена, нажмите "Готово".
  1. В списке USB устройств должен появиться "FreeBT USB Driver".

Обратитесь к документации проекта FreeBT для получения более подробной информации.

# УСТАНОВКА #

  1. Установите Visual Studio 2005 или 2008 и последние пакеты обновлений. Ваша Visual Studio инсталяция должна включать Smart Device Programmability функциональность.
  1. Установите Microsoft Device Emulator. У вас уже может быть он установлен вместе с Visual Studio инсталяцией. Обновите его до [Microsoft Device Emulator 3.0 -- Standalone Release](http://www.microsoft.com/downloads/details.aspx?familyid=A6F6ADAF-12E3-4B2F-A394-356E2C2FB114&displaylang=en).
  1. Установите образы ОС, которые вам нужны.
  1. У вас должно быть свободное Bluetooth USB устройство. Установите его в свободный USB порт.
  1. Установите FreeBT USB драйвер как описано в секции. УСТАНОВКА BLUETOOTH USB ДРАЙВЕРА.
  1. Установите [Microsoft Remote Tools Framework 1.00](http://www.microsoft.com/downloads/details.aspx?FamilyID=35e9ef0f-833f-4987-9d1f-157a0a6a76e4&DisplayLang=en).

# НАЧАЛО РАБОТЫ #

  1. Установите FreeBT USB драйвер как описано в секции УСТАНОВКА BLUETOOTH USB ДРАЙВЕРА.
  1. Установите ВСЕ из секции ТРЕБОВАНИЯ как описано в секции УСТАНОВКА.
  1. Запустите Remote Tools Framework плагин `BthEmulManager.cetool` из папки "RTFx Plugin".
  1. Выберите нужный образ ОС из списка.
  1. Подождите пока эмулятор будет запущен.
  1. Выберите "Bluetooth for Microsoft Device Emulator" узел в дереве.
  1. Если Bluetooth устройство было соединено успешно тогда информация о Bluetooth устройстве (Адрес, Производитель, HCI Версия, LMP Версия) будет отображена. Bluetooth теперь должен быть работоспособным на эмуляторе. В противном случае будет отображен код ошибки и ее описание.
  1. Чтобы очистить журнал обмена данными нажмите правую кнопку мыши и выберите "Clear All".
  1. Чтобы скопировать текущую информацию об устройстве в буфер обмена выделите "Bluetooth for Microsoft Device Emulator" узел в дереве, нажмите правую кнопку мыши и выберите "Copy to Clipboard".
  1. Чтобы выключить Bluetooth в эмуляторе откройте меню "Connection" и выберите "Disconnect from ... emulator".
  1. Microsoft Remote Tools Framework позволяет запустить два эмулятора одновременно. Если у вас установлено два или более FreeBT USB устройства откройте меню "Windows" и выберите "Split Windows View". Повторите шаги с 3 по 6. Вы получите два эмулятора в поддержкой Bluetooth работающих одновременно.
  1. Возможно включить/отключить логирование на стороне эмулятора. Если установлен флаг "Device Logging", то удаленное логирование будет включено на эмуляторе. Посмотрите в папку `\\Temp` на эмуляторе. Там должны быть созданы файлы `btd_bthemul_0.txt`, `btd_BthEmulAgent_0.txt`, `btd_bthemulcom_0.txt`.
  1. Возможно включить/отключить логирование на стороне ПК. Если установлен флаг "Desktop Logging", то логирование на ПК будет включено. Посмотрите в папку установки проекта. Там должен быть создан `BthEmulManager.txt` файл.
  1. Возможно включить/отключить логирование обмена данными. Логирование обмена данными позволяет увидеть передачу данных между эмулятором и Bluetooth устройством.

# РЕШЕНИЕ ПРОБЛЕМ #

Q. Я установил FreeBT USB Driver, но после запуска эмуляторе Bluetooth все еще не работает.<br>
A. Установите Microsoft Remote Tools Framework 1.00 если вы еще этого не сделали. Запустите Remote Tools Framework плагин <code>BthEmulManager.cetool</code> из папки "RTFx Plugin".<br>
<br>
<br>
Q. Я пытаюсь запустить Pocket PC 2003 SE Emulator, но все время получаю ошибку: "The device Pocket PC 2003 SE VGA Emulator has a CPU type of ARMV4 and an operating system version of 4.21."<br>
A. Pocket PC 2003 и Smartphone 2003 в настоящий момент не поддерживаются.<br>
<br>
<br>
Q. О каком Диспетчере устройств говорится в файле README ?<br>
A. Win2K&XP: Пуск -> Настройка -> Панель управления -> Система -> Оборудование -> Диспетчер устройств<br>
<br>Vista: Пуск -> Настройка -> Панель управления -> Оборудование и звук -> Диспетчер устройств<br>
<br>
<br>
Q. Я запустил <code>BthEmulManager.cetool</code> плагин в первый раз, но ничего не происходит. В эмуляторе нет Bluetooth.<br>
A. Попробуйте перезапустить плагин для того же самого образа эмулятора. Также на эмуляторе Settings -> Connections -> Bluetooth -> Mode tab и включите Bluetooth.<br>
<br>
Также вполне возможны проблемы с самим FreeBT USB драйвером. Драйвер все еще в (и наверное останется на этой стадии) в альфа версии. Существует ряд проблем с ним:<br>
<ol><li>Драйвер может прекратить корректную работу без видимых причин.<br>
</li><li>Драйвер может терять пакеты при операциях чтения/записи. Проблемы начинаются когда вы пытаетесь посылать большие блоки данных очень быстро. Скорее всего проблема в некорректном использовании HCI буферов (Read Buffer Size Command, Number Of Completed Packets Event).<br>
</li><li>Драйвер не стабилен на некоторых чипсетах типа CSR.</li></ol>

Но этот драйвер работает вполне стабильно для меня по крайней мере. Если же вы имеете опыт в разработке драйверов под Windows и испытываете выше перечисленные проблемы попробуйте улучшить драйвер и поделитесь результатами.<br>
<br>
Если все же спустя время драйвер перестал вести себя адекватно, зайдите в Диспетчер устройств, выделите FreeBT USB Driver из списка USB устройств, нажмите правую кнопку мыши и выберите "Отключить" из всплывающего меню. После чего опять же нажмите правую кнопку мыши и выберите "Включить" из всплывающего меню.<br>
<br>
<br>
<h1>БЛАГОДАРНОСТИ</h1>

Спасибо Antony C. Roberts за <a href='http://freebt.net/'>FreeBT</a> проект. Без него этот проект мог бы быть невозможным.