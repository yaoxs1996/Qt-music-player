#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "ui_widget.h"

#include <QListWidgetItem>
#include <QtMultimedia/QMediaPlayer>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>

class QMediaPlayer;
class QMediaPlaylist;
class QMenu;
class QAction;
class Widget : public QWidget
{
	Q_OBJECT

public:
	Widget(QWidget *parent = 0);
	~Widget();

private:
	Ui::WidgetClass ui;
	QMediaPlayer *player;		//播放器
	QMediaPlaylist *playList;		//播放列表
	QPushButton *btn_last;      //上一首
	QPushButton *btn_next;      //下一首
	QPushButton *btn_start;     //播放
	QPushButton *btn_stop;		//停止
	QPushButton *btn_open;      //打开文件
	QPushButton *btn_cut;		//剪切
	QSlider *progress;      //进度条
	QSlider *volumeBar;		//音量
	QListWidget *listWidget;        //歌曲显示区域
	QLabel *label;		//显示当前播放的音频名
	QLabel *timeLabel;
	QLineEdit *begin;		//用于输入剪切开始时间
	QLineEdit *end;		//输入剪切结束时间
	int timerID;		//定时器标识符

protected slots:
	virtual void timerEvent(QTimerEvent *event);

private slots:
	void slot_playMusic(QString FilePath);		//音频播放
	void slot_setPosition(int value);		//设置音频当前的播放时间点
	void slot_durationChanged(qint64 duration);		//获取音频时间以设置进度条
	void slot_positionChanged(qint64 position);		//进度条改变
	void slot_player_stateChanged(QMediaPlayer::State state);		//播放状态改变
	void slot_updateList(int value);		//更新播放列表
	void slot_stop();		//停止播放

	void playAudio();
	void next();		//播放上一首音频
	void last();		//播放下一首音频
	void open();		//浏览音频文件
	void volumeChanged();
	void createFile();		//创建用于剪切文件的批处理文件
};

#endif // WIDGET_H
