#include "playersound.h"
#include "playercontrols.h"
#include "playlistmodel.h"
#include <QMediaPlaylist>
#include <QtWidgets>

PlayerSound::PlayerSound(QWidget * parent):QWidget(parent)
{
    player = new QMediaPlayer(this);
    playlist = new QMediaPlaylist();
    player->setPlaylist(playlist);

    connect(player,SIGNAL(durationChanged(qint64)),SLOT(durationChanged(qint64)));

    QPushButton *chargeButton = new QPushButton(tr("Charger"), this);
    connect(chargeButton, SIGNAL(clicked()), this, SLOT(open()));

    PlayerControls *controls = new PlayerControls(this);
    controls->setState(player->state());

    connect(controls, SIGNAL(play()), player, SLOT(play()));
    connect(controls, SIGNAL(pause()), player, SLOT(pause()));
    connect(controls, SIGNAL(stop()), player, SLOT(stop()));
    connect(controls, SIGNAL(next()), playlist, SLOT(next()));
    connect(controls, SIGNAL(previous()), this, SLOT(previousClicked()));

    playlistModel = new PlaylistModel(this);
    playlistModel->setPlaylist(playlist);

    playlistView = new QListView(this);
    playlistView->setModel(playlistModel);
    playlistView->setCurrentIndex(playlistModel->index(playlist->currentIndex(), 0));

    playlistView->setFixedSize(300,200);
    QBoxLayout *displayLayout = new QHBoxLayout;
    displayLayout->addWidget(playlistView);

    QBoxLayout *controlLayout = new QHBoxLayout;
    controlLayout->setMargin(0);
    controlLayout->addWidget(chargeButton);
    controlLayout->addStretch(5);
    controlLayout->addWidget(controls);
    controlLayout->addStretch(5);

    controls->setEnabled(true);
    chargeButton->setEnabled(true);

    QBoxLayout *layout = new QVBoxLayout;
    layout->addLayout(displayLayout);
    layout->addLayout(controlLayout);

    setLayout(layout);

    QStringList arguments = qApp->arguments();
    arguments.removeAt(0);
    addToPlaylist(arguments);
}

PlayerSound::~PlayerSound()
{
}

void PlayerSound::open(){
    QStringList fileNames;
    QString paths = qApp->applicationDirPath();
    QString path = paths %"/sound/Rocky theme.flac";
    fileNames.push_back(path);

    path =  paths %"/sound/Trainer Red Epic Remix.mp3";
    fileNames.push_back(path);

    path =  paths %"/sound/Oblivion.ogg";
    fileNames.push_back(path);

    path =  paths %"/sound/Mastered.wav";
    fileNames.push_back(path);

    addToPlaylist(fileNames);
}

void PlayerSound::addToPlaylist(const QStringList& fileNames)
{
    foreach (QString const &argument, fileNames) {
        QFileInfo fileInfo(argument);
        if (fileInfo.exists()) {
            QUrl url = QUrl::fromLocalFile(fileInfo.absoluteFilePath());
            if (fileInfo.suffix().toLower() == QLatin1String("m3u")) {
                playlist->load(url);
            } else
                playlist->addMedia(url);
        } else {
            QUrl url(argument);
            if (url.isValid()) {
                playlist->addMedia(url);
            }
        }
    }
}

void PlayerSound::durationChanged(qint64 duration)
{
    this->duration = duration/1000;
}


void PlayerSound::previousClicked()
{
    // Go to previous track if we are within the first 5 seconds of playback
    // Otherwise, seek to the beginning.
    if(player->position() <= 5000)
        playlist->previous();
    else
        player->setPosition(0);
}
