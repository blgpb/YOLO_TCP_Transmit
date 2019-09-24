#include<iostream>

#include<winsock.h>
#include <opencv2/opencv.hpp>
#pragma comment(lib,"ws2_32.lib")

using namespace std;

void initialization();

int main() {

	//���峤�ȱ���

	int send_len = 0;

	int recv_len = 0;

	//���巢�ͻ������ͽ��ܻ�����

	char send_buf[100];

	char recv_buf[100];

	//���������׽��֣����������׽���

	SOCKET s_server;

	//����˵�ַ�ͻ��˵�ַ

	SOCKADDR_IN server_addr;

	initialization();

	//���������Ϣ

	server_addr.sin_family = AF_INET;

	server_addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");

	server_addr.sin_port = htons(1234);

	//�����׽���

	s_server = socket(AF_INET, SOCK_STREAM, 0);

	if (connect(s_server, (SOCKADDR*)& server_addr, sizeof(SOCKADDR)) == SOCKET_ERROR) {

		cout << "����������ʧ�ܣ�" << endl;

		WSACleanup();

	}

	else {

		cout << "���������ӳɹ���" << endl;

	}



	//����,��������

	while (1) {

		cout << "�����뷢����Ϣ:";

		cin >> send_buf;

		send_len = send(s_server, send_buf, 100, 0);

		if (send_len < 0) {

			cout << "����ʧ�ܣ�" << endl;

			break;

		}

		recv_len = recv(s_server, recv_buf, 100, 0);

		if (recv_len < 0) {

			cout << "����ʧ�ܣ�" << endl;

			break;

		}

		else {

			cout << "��Ʒʶ����:" << recv_buf << endl;
			cv::Mat mat_img = cv::imread(recv_buf);
			cv::imshow("detection_result", mat_img);
			cv::waitKey(1);
		}



	}

	//�ر��׽���

	closesocket(s_server);

	//�ͷ�DLL��Դ

	WSACleanup();

	return 0;

}

void initialization() {

	//��ʼ���׽��ֿ�

	WORD w_req = MAKEWORD(2, 2);//�汾��

	WSADATA wsadata;

	int err;

	err = WSAStartup(w_req, &wsadata);

	if (err != 0) {

		cout << "��ʼ���׽��ֿ�ʧ�ܣ�" << endl;

	}

	else {

		cout << "��ʼ���׽��ֿ�ɹ���" << endl;

	}

	//���汾��

	if (LOBYTE(wsadata.wVersion) != 2 || HIBYTE(wsadata.wHighVersion) != 2) {

		cout << "�׽��ֿ�汾�Ų�����" << endl;

		WSACleanup();

	}

	else {

		cout << "�׽��ֿ�汾��ȷ��" << endl;

	}

	//������˵�ַ��Ϣ



}