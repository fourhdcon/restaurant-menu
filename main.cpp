#include <iostream>
#include <fstream>
#include <mysql/mysql.h>
#include <vector>
#include </usr/include/cgicc/Cgicc.h>

void errorShow(const std::string &);

void mysqlErrorShow(MYSQL *, const std::string &);

//auto readPassFromFile(std::string);
std::vector<std::string> readPassFromFile(const std::string &src) {
	std::vector<std::string> result;
	std::string temp;
	std::ifstream file;
	file.open(src);
	if (!file.is_open()) errorShow("file_error");

	for (size_t i = 0; !file.eof(); ++i) {
		std::getline(file, temp);
		result.push_back(temp);
	}

	file.close();

	return std::move(result);
}

int main() {
	cgicc::Cgicc formData;
	std::string type = "view";
	/*auto it = formData.getElement("type");

	std::cout << "Content-type:text/html\r\n\r\n";

	if (it != formData.getElements().end())
		type = formData("type");
	else errorShow("cgicc_error");*/

	auto passes = readPassFromFile("mysqlConnectionPass.txt");

	MYSQL *mysqlConnection = mysql_init(nullptr);
	if (mysqlConnection == nullptr) errorShow("mysql_init_error");
	if (mysql_real_connect(mysqlConnection, passes[0].c_str(), passes[1].c_str(), passes[2].c_str(), passes[3].c_str(), static_cast<unsigned int>
						   (std::strtoul(passes[4].c_str(), nullptr, 0)),
						   nullptr, 0)
		== nullptr) {
		mysqlErrorShow(mysqlConnection, "mysql_connection_error");
	}

	mysql_query(mysqlConnection, "SET NAMES utf8");

	MYSQL_RES *queryId;
	MYSQL_ROW mysqlRow;

	mysql_select_db(mysqlConnection, passes[3].c_str());

	if (type == "view") {
		if (mysql_query(mysqlConnection, "SELECT name,imgURL FROM `list` ORDER BY `lp` ASC"))
			mysqlErrorShow(mysqlConnection, "mysql_query_error");

		queryId = mysql_store_result(mysqlConnection);

		while ((mysqlRow = mysql_fetch_row(queryId)) != nullptr) {
			std::cout << mysqlRow[0] << '\n' << mysqlRow[1] << '\n';
		}
	}

	mysql_close(mysqlConnection);

	return 0;
}

void errorShow(const std::string &errorText) {
	std::cout << errorText;
	exit(1);
}

void mysqlErrorShow(MYSQL *mysqlConnection, const std::string &errorText) {
	std::cout << errorText;
	mysql_close(mysqlConnection);
	exit(1);
}