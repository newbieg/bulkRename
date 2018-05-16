#include <QCoreApplication>
#include <QDir>
#include <QFileInfo>
#include <QFileInfoList>

#include <stdio.h>
#include <cstring>
#include <string>

bool swapWords(string &sentence, string bad, string good);



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    printf("path=%s \n", QDir::currentPath().toStdString().c_str());

    QString fname;
    QString newName;
    string fname_str;

    if(argc == 2)
    {
	string word = argv[1]
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
		fname_str = fname.from

		string changeString = fname.toStdString();
		while(swapWords(changeString, argv[1], ""))
                {
			charFound = true;
                }
                if(charFound)
                {
                    printf("New Name = %s\n", newName.toStdString().c_str());
                    rename(fname.toStdString().c_str(), newName.toStdString().c_str());
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


bool swapWords(string &sentence, string bad, string good)
{
	int found = sentence.find(bad);
	sentence.replace(sentence.find(bad), bad.length(), good);
	return found != string::npos;
}





