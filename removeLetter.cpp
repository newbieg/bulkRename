#include <QCoreApplication>
#include <QDir>
#include <QFileInfo>
#include <QFileInfoList>

#include <stdio.h>
#include <cstring>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    printf("path=%s \n", QDir::currentPath().toStdString().c_str());

    QString fname;
    QString newName;

    if(argc == 2)
    {
        if(strlen(argv[1]) == 1)
        {
            char letter[1];
            letter[0] = argv[1][0];
            printf("Input character = %s\n", letter);

            QDir dir(QDir::currentPath());
            QFileInfoList files = dir.entryInfoList();

            foreach(QFileInfo file, files)
            {
                bool charFound = false;
                if(!file.isDir())
                {
                    fname.clear();
                    newName.clear();
                    fname = file.fileName();

                    for(int i = 0; i < fname.length(); i ++)
                    {
                        if(argv[1][0] != fname.at(i))
                        {
                            newName += fname[i];
                        }
                        else
                        {
                            charFound = true;
                        }

                    }

                    if(charFound)
                    {
                        printf("New Name = %s\n", newName.toStdString().c_str());
                        rename(fname.toStdString().c_str(), newName.toStdString().c_str());
                    }
                }
            }
        }
    }
    else
    {
        printf("\nBe careful with this one, will remove any letter from all file-names in the current directory.\n");
        printf("Does not check for name-clashes before renaming, you may lose files if not carfull\n");
        printf("removeLetter 'l'\n");
        printf("Will Remove all 'l' chars from all file-names in the current directory\n");
        printf("You may have to be inventive if you want to remove common escape-chars like \\ # $ etc.");
    }
    std::exit(0);
    return a.exec();
}
