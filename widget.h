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
	QMediaPlayer *player;		//������
	QMediaPlaylist *playList;		//�����б�
	QPushButton *btn_last;      //��һ��
	QPushButton *btn_next;      //��һ��
	QPushButton *btn_start;     //����
	QPushButton *btn_stop;		//ֹͣ
	QPushButton *btn_open;      //���ļ�
	QPushButton *btn_cut;		//����
	QSlider *progress;      //������
	QSlider *volumeBar;		//����
	QListWidget *listWidget;        //������ʾ����
	QLabel *label;		//��ʾ��ǰ���ŵ���Ƶ��
	QLabel *timeLabel;
	QLineEdit *begin;		//����������п�ʼʱ��
	QLineEdit *end;		//������н���ʱ��
	int timerID;		//��ʱ����ʶ��

protected slots:
	virtual void timerEvent(QTimerEvent *event);

private slots:
	void slot_playMusic(QString FilePath);		//��Ƶ����
	void slot_setPosition(int value);		//������Ƶ��ǰ�Ĳ���ʱ���
	void slot_durationChanged(qint64 duration);		//��ȡ��Ƶʱ�������ý�����
	void slot_positionChanged(qint64 position);		//�������ı�
	void slot_player_stateChanged(QMediaPlayer::State state);		//����״̬�ı�
	void slot_updateList(int value);		//���²����б�
	void slot_stop();		//ֹͣ����

	void playAudio();
	void next();		//������һ����Ƶ
	void last();		//������һ����Ƶ
	void open();		//�����Ƶ�ļ�
	void volumeChanged();
	void createFile();		//�������ڼ����ļ����������ļ�
};

#endif // WIDGET_H
