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
#include "json.h"
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
	CvxText text(".\\fonts\\msyh.ttc"); //指定显示汉字的字体	
	cv::Scalar size{ 20, 0, 1, 0 }; // (字体大小, 无效的, 字符间距, 无效的 }

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
				text.putText(mat_img, "泡豇豆炒肉", cv::Point2f(i.x, i.y - 10), cv::Scalar(0, 0, 0));

			}
			if (obj_name == "qcmg")
			{
				text.setFont(nullptr, &size, nullptr, 0);
				text.putText(mat_img, "青菜蘑菇", cv::Point2f(i.x, i.y - 10), cv::Scalar(0, 0, 0));
			}
			if (obj_name == "xlh")
			{
				text.setFont(nullptr, &size, nullptr, 0);
				text.putText(mat_img, "西蓝花", cv::Point2f(i.x, i.y - 10), cv::Scalar(0, 0, 0));

			}
			if (obj_name == "baicai")
			{
				text.setFont(nullptr, &size, nullptr, 0);
				text.putText(mat_img, "白菜", cv::Point2f(i.x, i.y - 10), cv::Scalar(0, 0, 0));
			}
			if (obj_name == "dy")
			{
				text.setFont(nullptr, &size, nullptr, 0);
				text.putText(mat_img, "带鱼", cv::Point2f(i.x, i.y - 10), cv::Scalar(0, 0, 0));
			}

			if (obj_name == "htc")
			{
				text.setFont(nullptr, &size, nullptr, 0);
				text.putText(mat_img, "火腿肠", cv::Point2f(i.x, i.y - 10), cv::Scalar(0, 0, 0));

			}
			if (obj_name == "merp")
			{
				text.setFont(nullptr, &size, nullptr, 0);
				text.putText(mat_img, "木耳肉片", cv::Point2f(i.x, i.y - 10), cv::Scalar(0, 0, 0));
			}
			if (obj_name == "hc")
			{
				text.setFont(nullptr, &size, nullptr, 0);
				text.putText(mat_img, "花菜", cv::Point2f(i.x, i.y - 10), cv::Scalar(0, 0, 0));
			}

			if (obj_name == "sy")
			{
				text.setFont(nullptr, &size, nullptr, 0);
				text.putText(mat_img, "山药", cv::Point2f(i.x, i.y - 10), cv::Scalar(0, 0, 0));

			}
			if (obj_name == "mpdf")
			{
				text.setFont(nullptr, &size, nullptr, 0);
				text.putText(mat_img, "麻婆豆腐", cv::Point2f(i.x, i.y - 10), cv::Scalar(0, 0, 0));
			}
			if (obj_name == "hgr")
			{
				text.setFont(nullptr, &size, nullptr, 0);
				text.putText(mat_img, "回锅肉", cv::Point2f(i.x, i.y - 10), cv::Scalar(0, 0, 0));
			}

			if (obj_name == "sjdfz")
			{
				text.setFont(nullptr, &size, nullptr, 0);
				text.putText(mat_img, "四季豆腐竹", cv::Point2f(i.x, i.y - 10), cv::Scalar(0, 0, 0));

			}
			if (obj_name == "jdqz")
			{
				text.setFont(nullptr, &size, nullptr, 0);
				text.putText(mat_img, "豇豆茄子", cv::Point2f(i.x, i.y - 10), cv::Scalar(0, 0, 0));
			}
			if (obj_name == "xsr")
			{
				text.setFont(nullptr, &size, nullptr, 0);
				text.putText(mat_img, "小酥肉", cv::Point2f(i.x, i.y - 10), cv::Scalar(0, 0, 0));
			}

			if (obj_name == "kgcjd")
			{
				text.setFont(nullptr, &size, nullptr, 0);
				text.putText(mat_img, "苦瓜炒鸡蛋", cv::Point2f(i.x, i.y - 10), cv::Scalar(0, 0, 0));

			}
			if (obj_name == "tds")
			{
				text.setFont(nullptr, &size, nullptr, 0);
				text.putText(mat_img, "土豆丝", cv::Point2f(i.x, i.y - 10), cv::Scalar(0, 0, 0));
			}
			if (obj_name == "qcxgrs")
			{
				text.setFont(nullptr, &size, nullptr, 0);
				text.putText(mat_img, "芹菜香干肉丝", cv::Point2f(i.x, i.y - 10), cv::Scalar(0, 0, 0));
			}

			if (obj_name == "smrs")
			{
				text.setFont(nullptr, &size, nullptr, 0);
				text.putText(mat_img, "蒜苗肉丝", cv::Point2f(i.x, i.y - 10), cv::Scalar(0, 0, 0));

			}
			if (obj_name == "zd")
			{
				text.setFont(nullptr, &size, nullptr, 0);
				text.putText(mat_img, "蒸蛋", cv::Point2f(i.x, i.y - 10), cv::Scalar(0, 0, 0));
			}
			if (obj_name == "tdsjd")
			{
				text.setFont(nullptr, &size, nullptr, 0);
				text.putText(mat_img, "土豆四季豆", cv::Point2f(i.x, i.y - 10), cv::Scalar(0, 0, 0));
			}

			if (obj_name == "ws")
			{
				text.setFont(nullptr, &size, nullptr, 0);
				text.putText(mat_img, "莴笋", cv::Point2f(i.x, i.y - 10), cv::Scalar(0, 0, 0));

			}
			if (obj_name == "ldy")
			{
				text.setFont(nullptr, &size, nullptr, 0);
				text.putText(mat_img, "绿豆芽", cv::Point2f(i.x, i.y - 10), cv::Scalar(0, 0, 0));
			}
			if (obj_name == "hdy")
			{
				text.setFont(nullptr, &size, nullptr, 0);
				text.putText(mat_img, "黄豆芽", cv::Point2f(i.x, i.y - 10), cv::Scalar(0, 0, 0));
			}

			if (obj_name == "bc")
			{
				text.setFont(nullptr, &size, nullptr, 0);
				text.putText(mat_img, "包菜", cv::Point2f(i.x, i.y - 10), cv::Scalar(0, 0, 0));

			}
			if (obj_name == "yxqz")
			{
				text.setFont(nullptr, &size, nullptr, 0);
				text.putText(mat_img, "鱼香茄子", cv::Point2f(i.x, i.y - 10), cv::Scalar(0, 0, 0));
			}
			if (obj_name == "fqjdt")
			{
				text.setFont(nullptr, &size, nullptr, 0);
				text.putText(mat_img, "番茄鸡蛋汤", cv::Point2f(i.x, i.y - 10), cv::Scalar(0, 0, 0));
			}
			if (obj_name == "hsyk")
			{
				text.setFont(nullptr, &size, nullptr, 0);
				text.putText(mat_img, "红烧鱼块", cv::Point2f(i.x, i.y - 10), cv::Scalar(0, 0, 0));

			}
			if (obj_name == "yxrs")
			{
				text.setFont(nullptr, &size, nullptr, 0);
				text.putText(mat_img, "鱼香肉丝", cv::Point2f(i.x, i.y - 10), cv::Scalar(0, 0, 0));
			}
			if (obj_name == "mf")
			{
				text.setFont(nullptr, &size, nullptr, 0);
				text.putText(mat_img, "米饭", cv::Point2f(i.x, i.y - 10), cv::Scalar(0, 0, 0));
			}
			if (obj_name == "qc")
			{
				text.setFont(nullptr, &size, nullptr, 0);
				text.putText(mat_img, "青菜", cv::Point2f(i.x, i.y - 10), cv::Scalar(0, 0, 0));

			}
			if (obj_name == "ymht")
			{
				text.setFont(nullptr, &size, nullptr, 0);
				text.putText(mat_img, "玉米火腿", cv::Point2f(i.x, i.y - 10), cv::Scalar(0, 0, 0));
			}
			if (obj_name == "tdjk")
			{
				text.setFont(nullptr, &size, nullptr, 0);
				text.putText(mat_img, "土豆鸡块", cv::Point2f(i.x, i.y - 10), cv::Scalar(0, 0, 0));
			}
		}
	}
	if (current_det_fps >= 0 && current_cap_fps >= 0) {
		std::string fps_str = "FPS detection: " + std::to_string(current_det_fps) + "   FPS capture: " + std::to_string(current_cap_fps);
		putText(mat_img, fps_str, cv::Point2f(10, 20), cv::FONT_HERSHEY_COMPLEX_SMALL, 1.2, cv::Scalar(50, 255, 0), 2);
	}
}

void initialization();
string getJson(std::vector<bbox_t> result_vec, std::vector<std::string> obj_names);
int main() {

	std::string  names_file = "dish_detection.names";
	std::string  cfg_file = "dish_detection.cfg";
	std::string  weights_file = "dish_detection.weights";
	std::string filename;
	Detector detector(cfg_file, weights_file);
	auto obj_names = objects_names_from_file(names_file);
	//定义长度变量

	int send_len = 0;

	int recv_len = 0;

	int len = 0;

	//定义发送缓冲区和接受缓冲区

	char send_buf[100];

	char recv_buf[100];

	//定义服务端套接字，接受请求套接字

	SOCKET s_server;

	SOCKET s_accept;

	//服务端地址客户端地址

	SOCKADDR_IN server_addr;

	SOCKADDR_IN accept_addr;

	initialization();

	//填充服务端信息

	server_addr.sin_family = AF_INET;

	server_addr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);

	server_addr.sin_port = htons(1234);

	//创建套接字 
	s_server = socket(AF_INET, SOCK_STREAM, 0); 
	if (bind(s_server, (SOCKADDR*)& server_addr, sizeof(SOCKADDR)) == SOCKET_ERROR) { 
		cout << "套接字绑定失败！" << endl; 
	} 
	else { 
		cout << "套接字绑定成功！" << endl; 
	}
	//设置套接字为监听状态 
	if (listen(s_server, SOMAXCONN) < 0) { 
		cout << "设置监听状态失败！" << endl;  
	} 
	else { 
		cout << "设置监听状态成功！" << endl; 
	} 
	cout << "服务端正在监听连接，请稍候...." << endl; 
	//接收数据
	bool flgConnected = false;
	while (1) {
		Sleep(10);
		if (!flgConnected) {
			
			//接受连接请求 
			len = sizeof(SOCKADDR); 
			s_accept = accept(s_server, (SOCKADDR*)& accept_addr, &len); 
			if (s_accept == SOCKET_ERROR) { 
				cout << "连接失败！" << endl;   
			}
			else {
				cout << "连接建立，准备接受数据" << endl;
				flgConnected = true;
			}
			
		}
		if (flgConnected) {
			memset(recv_buf, 0, 100);
			recv_len = recv(s_accept, recv_buf, 100, 0); 
			if (recv_len <0) { 
				cout << "断开连接！" << endl; 
				flgConnected = false;
				closesocket(s_accept); 
			} else if(recv_len>0){

				cout << "客户端信息:" << recv_buf << endl;
				cv::Mat mat_img = cv::imread(recv_buf);
				if (!mat_img.empty())
				{
					std::vector<bbox_t> result_vec = detector.detect(mat_img);
					draw_boxes(mat_img, result_vec, obj_names);
					string jsonstr = getJson(result_vec, obj_names);
					cv::imwrite("result.jpg", mat_img);
					cout << "菜品识别结果:"<<result_vec.size();  
					send_len = send(s_accept, jsonstr.data(), jsonstr.length(), 0);
					if (send_len < 0) { 
						cout << "发送失败！" << endl; 
						flgConnected = false;
						closesocket(s_accept); 
						//break;

					}
				}
				else {
					cout << "读取缓存图像出错！" << endl;
					string msg="File Path Error";
					send_len = send(s_accept, msg.data(), msg.length(), 0);
					if (send_len < 0) {
						cout << "发送失败！" << endl; 
						//break; 
					}
					flgConnected = false;
					closesocket(s_accept); 
				}
			} 
		} 
	} 
	//关闭套接字 
	closesocket(s_server); 
	closesocket(s_accept); 
	//释放DLL资源 
	WSACleanup(); 
	return 0;

}
string getJson(std::vector<bbox_t> result_vec, std::vector<std::string> obj_names) {
	Json::Value value(Json::arrayValue);
	for (auto var : result_vec) {
		Json::Value item;
		item["x"] = var.x;
		item["y"] = var.y;
		item["w"] = var.w;
		item["h"] = var.h;
		item["prob"] = var.prob;
		item["obj_id"] = var.obj_id;
		value.append(item);
	} 
	return value.toStyledString();
}
void initialization() {

	//初始化套接字库

	WORD w_req = MAKEWORD(2, 2);//版本号

	WSADATA wsadata;

	int err;

	err = WSAStartup(w_req, &wsadata);

	if (err != 0) {

		cout << "初始化套接字库失败！" << endl;

	}

	else {

		cout << "初始化套接字库成功！" << endl;

	}

	//检测版本号

	if (LOBYTE(wsadata.wVersion) != 2 || HIBYTE(wsadata.wHighVersion) != 2) {

		cout << "套接字库版本号不符！" << endl;

		WSACleanup();

	}

	else {

		cout << "套接字库版本正确！" << endl;

	}

	//填充服务端地址信息



}