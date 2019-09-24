#include<iostream>

#include<winsock.h>

#pragma comment(lib,"ws2_32.lib")

using namespace std;
#include <opencv2/opencv.hpp>
#include <iostream>
#include <iomanip> 
#include <string>
#include <vector>
#include <queue>
#include <fstream>
#include <thread>
#include <atomic>
#include <mutex>              // std::mutex, std::unique_lock
#include <condition_variable> // std::condition_variable
#include "opencv2/core/version.hpp"
#include "yolo_v2_class.hpp"
#include "CvxText.hpp"

#define OPENCV

std::vector<std::string> objects_names_from_file(std::string const filename) {
	std::ifstream file(filename);
	std::vector<std::string> file_lines;
	if (!file.is_open()) return file_lines;
	for (std::string line; getline(file, line);) file_lines.push_back(line);
	std::cout << "object names loaded \n";
	return file_lines;
}

void draw_boxes(cv::Mat mat_img, std::vector<bbox_t> result_vec, std::vector<std::string> obj_names,
	int current_det_fps = -1, int current_cap_fps = -1)
{
	CvxText text("D:\\��Ŀ\\YOLO_TCP_Transmit_server\\msyh.ttc"); //ָ����ʾ���ֵ�����	
	cv::Scalar size{ 20, 0, 1, 0 }; // (�����С, ��Ч��, �ַ����, ��Ч�� }

	int const colors[6][3] = { { 1,0,1 },{ 0,0,1 },{ 0,1,1 },{ 0,1,0 },{ 1,1,0 },{ 1,0,0 } };

	for (auto& i : result_vec) {

		if (obj_names.size() > i.obj_id) {
			std::string obj_name = obj_names[i.obj_id];

			cv::Scalar color = obj_id_to_color(i.obj_id);
			cv::rectangle(mat_img, cv::Rect(i.x, i.y, i.w, i.h), color, 3);

			if (i.track_id > 0) obj_name += " - " + std::to_string(i.track_id);
			cv::Size const text_size = getTextSize(obj_name, cv::FONT_HERSHEY_COMPLEX_SMALL, 1.2, 2, 0);
			int const max_width = (text_size.width > i.w + 2) ? text_size.width : (i.w + 2);
			cv::rectangle(mat_img, cv::Point2f(std::max((int)i.x - 1, 0), std::max((int)i.y - 30, 0)),
				cv::Point2f(std::min((int)i.x + 200, mat_img.cols - 1), std::min((int)i.y, mat_img.rows - 1)),
				color, -1, 8, 0);

			if (obj_name == "pjdcr")
			{
				text.setFont(nullptr, &size, nullptr, 0);
				text.putText(mat_img, "����������", cv::Point2f(i.x, i.y - 10), cv::Scalar(0, 0, 0));

			}
			if (obj_name == "qcmg")
			{
				text.setFont(nullptr, &size, nullptr, 0);
				text.putText(mat_img, "���Ģ��", cv::Point2f(i.x, i.y - 10), cv::Scalar(0, 0, 0));
			}
			if (obj_name == "xlh")
			{
				text.setFont(nullptr, &size, nullptr, 0);
				text.putText(mat_img, "������", cv::Point2f(i.x, i.y - 10), cv::Scalar(0, 0, 0));

			}
			if (obj_name == "baicai")
			{
				text.setFont(nullptr, &size, nullptr, 0);
				text.putText(mat_img, "�ײ�", cv::Point2f(i.x, i.y - 10), cv::Scalar(0, 0, 0));
			}
			if (obj_name == "dy")
			{
				text.setFont(nullptr, &size, nullptr, 0);
				text.putText(mat_img, "����", cv::Point2f(i.x, i.y - 10), cv::Scalar(0, 0, 0));
			}

			if (obj_name == "htc")
			{
				text.setFont(nullptr, &size, nullptr, 0);
				text.putText(mat_img, "���ȳ�", cv::Point2f(i.x, i.y - 10), cv::Scalar(0, 0, 0));

			}
			if (obj_name == "merp")
			{
				text.setFont(nullptr, &size, nullptr, 0);
				text.putText(mat_img, "ľ����Ƭ", cv::Point2f(i.x, i.y - 10), cv::Scalar(0, 0, 0));
			}
			if (obj_name == "hc")
			{
				text.setFont(nullptr, &size, nullptr, 0);
				text.putText(mat_img, "����", cv::Point2f(i.x, i.y - 10), cv::Scalar(0, 0, 0));
			}

			if (obj_name == "sy")
			{
				text.setFont(nullptr, &size, nullptr, 0);
				text.putText(mat_img, "ɽҩ", cv::Point2f(i.x, i.y - 10), cv::Scalar(0, 0, 0));

			}
			if (obj_name == "mpdf")
			{
				text.setFont(nullptr, &size, nullptr, 0);
				text.putText(mat_img, "���Ŷ���", cv::Point2f(i.x, i.y - 10), cv::Scalar(0, 0, 0));
			}
			if (obj_name == "hgr")
			{
				text.setFont(nullptr, &size, nullptr, 0);
				text.putText(mat_img, "�ع���", cv::Point2f(i.x, i.y - 10), cv::Scalar(0, 0, 0));
			}

			if (obj_name == "sjdfz")
			{
				text.setFont(nullptr, &size, nullptr, 0);
				text.putText(mat_img, "�ļ�������", cv::Point2f(i.x, i.y - 10), cv::Scalar(0, 0, 0));

			}
			if (obj_name == "jdqz")
			{
				text.setFont(nullptr, &size, nullptr, 0);
				text.putText(mat_img, "��������", cv::Point2f(i.x, i.y - 10), cv::Scalar(0, 0, 0));
			}
			if (obj_name == "xsr")
			{
				text.setFont(nullptr, &size, nullptr, 0);
				text.putText(mat_img, "С����", cv::Point2f(i.x, i.y - 10), cv::Scalar(0, 0, 0));
			}

			if (obj_name == "kgcjd")
			{
				text.setFont(nullptr, &size, nullptr, 0);
				text.putText(mat_img, "��ϳ�����", cv::Point2f(i.x, i.y - 10), cv::Scalar(0, 0, 0));

			}
			if (obj_name == "tds")
			{
				text.setFont(nullptr, &size, nullptr, 0);
				text.putText(mat_img, "����˿", cv::Point2f(i.x, i.y - 10), cv::Scalar(0, 0, 0));
			}
			if (obj_name == "qcxgrs")
			{
				text.setFont(nullptr, &size, nullptr, 0);
				text.putText(mat_img, "�۲������˿", cv::Point2f(i.x, i.y - 10), cv::Scalar(0, 0, 0));
			}

			if (obj_name == "smrs")
			{
				text.setFont(nullptr, &size, nullptr, 0);
				text.putText(mat_img, "������˿", cv::Point2f(i.x, i.y - 10), cv::Scalar(0, 0, 0));

			}
			if (obj_name == "zd")
			{
				text.setFont(nullptr, &size, nullptr, 0);
				text.putText(mat_img, "����", cv::Point2f(i.x, i.y - 10), cv::Scalar(0, 0, 0));
			}
			if (obj_name == "tdsjd")
			{
				text.setFont(nullptr, &size, nullptr, 0);
				text.putText(mat_img, "�����ļ���", cv::Point2f(i.x, i.y - 10), cv::Scalar(0, 0, 0));
			}

			if (obj_name == "ws")
			{
				text.setFont(nullptr, &size, nullptr, 0);
				text.putText(mat_img, "ݫ��", cv::Point2f(i.x, i.y - 10), cv::Scalar(0, 0, 0));

			}
			if (obj_name == "ldy")
			{
				text.setFont(nullptr, &size, nullptr, 0);
				text.putText(mat_img, "�̶�ѿ", cv::Point2f(i.x, i.y - 10), cv::Scalar(0, 0, 0));
			}
			if (obj_name == "hdy")
			{
				text.setFont(nullptr, &size, nullptr, 0);
				text.putText(mat_img, "�ƶ�ѿ", cv::Point2f(i.x, i.y - 10), cv::Scalar(0, 0, 0));
			}

			if (obj_name == "bc")
			{
				text.setFont(nullptr, &size, nullptr, 0);
				text.putText(mat_img, "����", cv::Point2f(i.x, i.y - 10), cv::Scalar(0, 0, 0));

			}
			if (obj_name == "yxqz")
			{
				text.setFont(nullptr, &size, nullptr, 0);
				text.putText(mat_img, "��������", cv::Point2f(i.x, i.y - 10), cv::Scalar(0, 0, 0));
			}
			if (obj_name == "fqjdt")
			{
				text.setFont(nullptr, &size, nullptr, 0);
				text.putText(mat_img, "���Ѽ�����", cv::Point2f(i.x, i.y - 10), cv::Scalar(0, 0, 0));
			}
			if (obj_name == "hsyk")
			{
				text.setFont(nullptr, &size, nullptr, 0);
				text.putText(mat_img, "�������", cv::Point2f(i.x, i.y - 10), cv::Scalar(0, 0, 0));

			}
			if (obj_name == "yxrs")
			{
				text.setFont(nullptr, &size, nullptr, 0);
				text.putText(mat_img, "������˿", cv::Point2f(i.x, i.y - 10), cv::Scalar(0, 0, 0));
			}
			if (obj_name == "mf")
			{
				text.setFont(nullptr, &size, nullptr, 0);
				text.putText(mat_img, "�׷�", cv::Point2f(i.x, i.y - 10), cv::Scalar(0, 0, 0));
			}
			if (obj_name == "qc")
			{
				text.setFont(nullptr, &size, nullptr, 0);
				text.putText(mat_img, "���", cv::Point2f(i.x, i.y - 10), cv::Scalar(0, 0, 0));

			}
			if (obj_name == "ymht")
			{
				text.setFont(nullptr, &size, nullptr, 0);
				text.putText(mat_img, "���׻���", cv::Point2f(i.x, i.y - 10), cv::Scalar(0, 0, 0));
			}
			if (obj_name == "tdjk")
			{
				text.setFont(nullptr, &size, nullptr, 0);
				text.putText(mat_img, "��������", cv::Point2f(i.x, i.y - 10), cv::Scalar(0, 0, 0));
			}
		}
	}
	if (current_det_fps >= 0 && current_cap_fps >= 0) {
		std::string fps_str = "FPS detection: " + std::to_string(current_det_fps) + "   FPS capture: " + std::to_string(current_cap_fps);
		putText(mat_img, fps_str, cv::Point2f(10, 20), cv::FONT_HERSHEY_COMPLEX_SMALL, 1.2, cv::Scalar(50, 255, 0), 2);
	}
}

void initialization();

int main() {

	//���峤�ȱ���

	int send_len = 0;

	int recv_len = 0;

	int len = 0;

	//���巢�ͻ������ͽ��ܻ�����

	char send_buf[100];

	char recv_buf[100];

	//���������׽��֣����������׽���

	SOCKET s_server;

	SOCKET s_accept;

	//����˵�ַ�ͻ��˵�ַ

	SOCKADDR_IN server_addr;

	SOCKADDR_IN accept_addr;

	initialization();

	//���������Ϣ

	server_addr.sin_family = AF_INET;

	server_addr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);

	server_addr.sin_port = htons(1234);

	//�����׽���

	s_server = socket(AF_INET, SOCK_STREAM, 0);

	if (bind(s_server, (SOCKADDR*)& server_addr, sizeof(SOCKADDR)) == SOCKET_ERROR) {

		cout << "�׽��ְ�ʧ�ܣ�" << endl;

		WSACleanup();

	}

	else {

		cout << "�׽��ְ󶨳ɹ���" << endl;

	}

	//�����׽���Ϊ����״̬

	if (listen(s_server, SOMAXCONN) < 0) {

		cout << "���ü���״̬ʧ�ܣ�" << endl;

		WSACleanup();

	}

	else {

		cout << "���ü���״̬�ɹ���" << endl;

	}

	cout << "��������ڼ������ӣ����Ժ�...." << endl;

	//������������

	len = sizeof(SOCKADDR);

	s_accept = accept(s_server, (SOCKADDR*)& accept_addr, &len);

	if (s_accept == SOCKET_ERROR) {

		cout << "����ʧ�ܣ�" << endl;

		WSACleanup();

		return 0;

	}

	cout << "���ӽ�����׼����������" << endl;

	std::string  names_file = "dish_detection.names";
	std::string  cfg_file = "dish_detection.cfg";
	std::string  weights_file = "dish_detection.weights";
	std::string filename;
	Detector detector(cfg_file, weights_file);
	auto obj_names = objects_names_from_file(names_file);


	//��������

	while (1) {

		recv_len = recv(s_accept, recv_buf, 100, 0);

		if (recv_len < 0) {

			cout << "����ʧ�ܣ�" << endl;

			break;

		}

		else {

			cout << "�ͻ�����Ϣ:" << recv_buf << endl;
			cv::Mat mat_img = cv::imread(recv_buf);
			std::vector<bbox_t> result_vec = detector.detect(mat_img);
			draw_boxes(mat_img, result_vec, obj_names);
			cv::imwrite("D:\\��Ŀ\\result.jpg", mat_img);

		}

		cout << "��Ʒʶ����:";

		strcpy(send_buf, "D:\\��Ŀ\\result.jpg");

		send_len = send(s_accept, send_buf, 100, 0);

		if (send_len < 0) {

			cout << "����ʧ�ܣ�" << endl;

			break;

		}

	}

	//�ر��׽���

	closesocket(s_server);

	closesocket(s_accept);

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