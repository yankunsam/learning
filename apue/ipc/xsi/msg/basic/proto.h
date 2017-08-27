#ifndef PROTO_H__
#define PROTO_H__

#define KEYPATH			"/etc/hosts"
#define KEYPROJ			'A'

#define NAMESIZE		32

#define MSG_STU			1

struct msg_st
{
	long mtype;
	char name[NAMESIZE];
	int math;
	int chinese;
};

#endif



