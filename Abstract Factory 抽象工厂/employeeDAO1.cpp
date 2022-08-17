#include <vector>

class SqlConnection;
class SqlCommand;
class SqlDataReader;

class EmployeeDAO {
public:
    std::vector<EmployeeDAO> GetEmployees() {
        SqlConnection* connection = new SqlConnection;
        connection->ConnectionString("...");

        SqlCommand* command = new SqlCommand;
        command->CommandText("...");
        command->setConnection(connection);

        SqlDataReader* reader = command->ExecuteReader();
        while (reader->Read()) {
            
        }
    }
};
