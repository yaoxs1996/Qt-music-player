#include "widget.h"
#include <QFileDialog>
#include <QFileInfo>
#include <QtmultiMedia/QMediaPlayer>
#include <QtmultiMedia/QMediaPlaylist>
#include <QDebug>
#include <QUrl>
#include <QFile>
#include <QMessageBox>
#include <QProcess>
#include <QDir>

Widget::Widget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//由于Qt对中文的支持原因，使用中文命名控件，可能无法通过编译
	//设置窗体名称与大小
	this->setWindowTitle("AudioPlayer");
	this->setMaximumSize(300, 350);
	this->setMinimumSize(300, 350);
	//实例化
	player = new QMediaPlayer(this);
	playList = new QMediaPlaylist(this);
	player->setPlaylist(playList);
	playList->setPlaybackMode(QMediaPlaylist::Loop);
	//上一曲按钮实例化
	btn_last = new QPushButton(this);
	btn_last->setText("Last");
	btn_last->setGeometry(QRect(25, 270, 50, 30));
	//下一首按钮实例化
	btn_next = new QPushButton(this);
	btn_next->setText("Next");
	btn_next->setGeometry(QRect(175, 270, 50, 30));
	//播放按钮实例化
	btn_start = new QPushButton(this);
	btn_start->setText("Play");
	btn_start->setGeometry(QRect(75, 270, 50, 30));
	//停止按钮
	btn_stop = new QPushButton(this);
	btn_stop->setText("Stop");
	btn_stop->setGeometry(QRect(125, 270, 50, 30));
	//打开文件按钮实例化
	btn_open = new QPushButton(this);
	btn_open->setText("Open");
	btn_open->setGeometry(QRect(225, 270, 50, 30));
	//进度条实例化
	progress = new QSlider(this);
	progress->setOrientation(Qt::Horizontal);		//设置为水平
	progress->setGeometry(QRect(5, 210, 290, 20));
	//音量
	volumeBar = new QSlider(this);
	volumeBar->setOrientation(Qt::Vertical);
	volumeBar->setGeometry(QRect(260,0,20,200));
	volumeBar->setRange(0, 100);
	volumeBar->setValue(50);
	//播放列表实例化
	listWidget = new QListWidget(this);
	listWidget->setGeometry(QRect(5, 0, 250, 200));
	//剪切按钮
	btn_cut = new QPushButton(this);
	btn_cut->setText("Cut");
	btn_cut->setGeometry(QRect(5, 310, 50, 30));
	//剪切开始时间输入栏
	begin = new QLineEdit(this);
	begin->setText("0:30");
	begin->setGeometry(QRect(60, 315, 40, 20));
	//剪切结束时间输入栏
	end = new QLineEdit(this);
	end->setText("0:45");
	end->setGeometry(QRect(110, 315, 40, 20));
	//显示当前播放的音频（居中显示）
	label = new QLabel(this);
	label->setGeometry(QRect(0, 235, 295, 20));
	label->setAlignment(Qt::AlignCenter);
	//获取当前音频的时间（未实现）
	timeLabel = new QLabel(this);
	timeLabel->setGeometry(QRect(140, 235, 40, 20));
	//timeLabel->setText("hello");

	//槽与信号
	//进度条
	connect(progress, SIGNAL(sliderMoved(int)), this, SLOT(slot_setPosition(int)));
	//播放器
	connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(slot_positionChanged(qint64)));
	connect(player, SIGNAL(durationChanged(qint64)), this, SLOT(slot_durationChanged(qint64)));
	connect(player, SIGNAL(stateChanged(QMediaPlayer::State)), this, SLOT(slot_player_stateChanged(QMediaPlayer::State)));
	//音量
	connect(volumeBar, SIGNAL(valueChanged(int)), this, SLOT(volumeChanged()));
	//播放列表
	connect(playList, SIGNAL(currentIndexChanged(int)), this, SLOT(slot_updateList(int)));
	//播放按钮
	connect(btn_start, SIGNAL(clicked(bool)), this, SLOT(playAudio()));
	connect(btn_start, SIGNAL(clicked(bool)), this, SLOT(slot_playMusic(QString)));
	//下一首按钮
	connect(btn_next, SIGNAL(clicked(bool)), this, SLOT(next()));
	//上一首按钮
	connect(btn_last, SIGNAL(clicked(bool)), this, SLOT(last()));
	//停止播放
	connect(btn_stop, SIGNAL(clicked(bool)), this, SLOT(slot_stop()));
	//浏览文件按钮
	connect(btn_open, SIGNAL(clicked(bool)), this, SLOT(open()));
	//剪切按钮
	connect(btn_cut, SIGNAL(clicked(bool)), this, SLOT(createFile()));
}

Widget::~Widget()
{

}

QByteArray addr;		//剪切保存新文件的文件名
QByteArray addr2;		//剪切的原文件的路径名

//定时器事件
void Widget::timerEvent(QTimerEvent *event)
{
	if (timerID == event->timerId())
	{
		int value = progress->value() + 1;
		progress->setValue(value);
		if (value == progress->maximum())
		{
			killTimer(timerID);
		}
	}
}

//选择打开文件
void Widget::open()
{
	QString initialName = QDir::homePath();
	QStringList pathList = QFileDialog::getOpenFileNames(this, tr("选择文件"), initialName, tr("*.wav *.mp3 *.wma *.ape *.flac"));
	for (int i = 0; i<pathList.size(); ++i)
	{
		QString path = QDir::toNativeSeparators(pathList.at(i));		//分隔符转换
		if (!path.isEmpty())
		{
			playList->addMedia(QUrl::fromLocalFile(path));
			QString fileName = path.split("\\").last();		//拆分字符串
			listWidget->addItem(fileName);
			addr = fileName.toUtf8();		//获取文件名
			addr2 = path.toUtf8();		//获取路径名
		}
	}
}

//播放
void Widget::slot_playMusic(QString FilePath)
{
	playList->setCurrentIndex(listWidget->currentIndex().row());
	player->play();
}

//停止播放
void Widget::slot_stop()
{
	player->stop();
}

//音频快进
void Widget::slot_setPosition(int value)
{
	player->setPosition(value);
}

//调节快进
void Widget::slot_positionChanged(qint64 position)
{
	progress->setValue(position);
}

//获取歌曲长度
void Widget::slot_durationChanged(qint64 duration)
{
	progress->setRange(0, duration);

}

//播放暂停切换
void Widget::playAudio()
{
	switch (player->state())
	{
	case QMediaPlayer::PlayingState:
		player->pause();
		break;
	default:
		player->play();
		break;
	}
}

//播放状态的改变
void Widget::slot_player_stateChanged(QMediaPlayer::State state)
{
	switch (state)
	{
	case QMediaPlayer::PlayingState:
		btn_start->setText("Pause");
		break;
	default:
		btn_start->setText("Play");
		break;
	}
}

//切换上一首
void Widget::last()
{
	int currentIndex = playList->currentIndex();
	if (--currentIndex<0)
		currentIndex = 0;
	playList->setCurrentIndex(currentIndex);
	player->play();
}

//切换到下一首
void Widget::next()
{
	int currentIndex = playList->currentIndex();
	if (++currentIndex == playList->mediaCount())
		currentIndex = 0;
	playList->setCurrentIndex(currentIndex);
	player->play();
}

//列表更新
void Widget::slot_updateList(int value)
{
	QListWidgetItem *item = listWidget->item(value);
	item->setSelected(true);
	label->setText(item->text());
}

//音量调节
void Widget::volumeChanged()
{
	player->setVolume(volumeBar->value());
}
//创建批处理文件进行剪切音频,文件名及地址不要包含复杂字符，如空格
void Widget::createFile()
{
	QFile file("D:/cut.bat");
	//创建输出文件夹。并判断是否存在
	QDir *folder = new QDir;
	bool exist = folder->exists("D://AudioOutput");
	if (exist)
	{
		QMessageBox::warning(this, tr("Create folder"), tr("Folder exist!"));
	}
	else
	{
		bool ok = folder->mkdir("D://AudioOutput");
		if (ok)
		{
			QMessageBox::warning(this, tr("Create folder"), tr("Success!"));
		}
		else
		{
			QMessageBox::warning(this, tr("Creare Folder"), tr("Failure!"));
		}
	}

	//创建批处理文件，并写入命令
	if (file.exists())
	{
		//如果同名批处理文件已存在，则提示，并执行删除操作
		QMessageBox::warning(this, "Create file", "File exist! Deleting...");
		file.remove();
		//再次创建文件
		file.open(QIODevice::ReadWrite | QIODevice::Text);
		//字符串格式转换
		QByteArray str1 = begin->text().toUtf8();
		QByteArray str2 = end->text().toUtf8();
		//向bat文件写入内容
		file.write("ffmpeg -i ");
		file.write(addr2);
		file.write(" -ss ");
		file.write(str1);
		file.write(" -t ");
		file.write(str2);
		file.write(" -c copy D:/AudioOutput/new_");
		file.write(addr);
		//文件创建成功的提示
		QMessageBox::warning(this, "Create file", "Create success!");
	}
	else
	{
		file.open(QIODevice::ReadWrite | QIODevice::Text);
		//字符串格式转换
		QByteArray str1 = begin->text().toUtf8();
		QByteArray str2 = end->text().toUtf8();
		//向bat文件写入内容
		file.write("ffmpeg -i ");
		file.write(addr2);
		file.write(" -ss ");
		file.write(str1);
		file.write(" -t ");
		file.write(str2);
		file.write(" -c copy D:/AudioOutput/new_");
		file.write(addr);
		file.write("\npause");
		//文件创建成功的提示
		QMessageBox::warning(this, "Create file", "Create success!");
	}
	file.close();
	//QProcess::execute("D:/cut.bat");		//执行bat文件，但不会弹出cmd窗口
	system("D:/cut.bat");		//弹出cmd窗口，防止等待命令，使程序无响应
	//file.remove();
}