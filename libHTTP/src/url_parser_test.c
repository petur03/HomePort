#include "url_parser.c"
#include "../../unit_test.h"
#include <string.h>

int on_begin_called_correctly = 0;
int on_protocol_called_correctly = 0;
int on_host_called_correctly = 0;
int on_port_called_correctly = 0;
int on_path_segment_called_correctly = 0;
int on_key_value_called_correctly = 0;

void on_begin()
{
	on_begin_called_correctly = 1;
}

void on_protocol(const char* protocol, int length)
{
	if(strncmp(protocol, "http", 4) == 0)
	{
		on_protocol_called_correctly = 1;
	}
}

void on_host(const char* host, int length)
{
	if(strncmp(host, "localhost", 9) == 0)
	{
		on_host_called_correctly = 1;
	}
}

void on_port(const char* port, int length)
{
	if(strncmp(port, "8080", 4) == 0)
	{
		on_port_called_correctly = 1;
	}
}

void on_path_segment(const char* seg, int length)
{
	if((length == 6 && strncmp(seg, "device",6) == 0) || (length == 2 && strncmp(seg, "tv",2) == 0))
	{
		on_path_segment_called_correctly++;
	}
}

void on_key_value(const char* key, int key_length, const char* value, int value_length)
{
	if(key_length == 2 && strncmp(key, "id", 2) == 0 && strncmp(value, "1",1) == 0)
	{
		on_key_value_called_correctly++;
	}

	if(key_length == 5 && strncmp(key, "brand", 5) == 0 && strncmp(value, "Apple",5) == 0)
	{
		on_key_value_called_correctly++;
	}

}

TEST_START("url_parser.c")

TEST(non chunked url parsing)

	char* url = "http://localhost:8080/device/tv?id=1&brand=Apple";
	int url_len = 48;

	struct url_parser_settings settings = URL_PARSER_SETTINGS_DEFAULT;

 	settings.on_begin = &on_begin;
 	settings.on_protocol = &on_protocol;
 	settings.on_host = &on_host;
 	settings.on_port = &on_port;
 	settings.on_path_segment = &on_path_segment;
 	settings.on_key_value = &on_key_value;

	struct url_parser_instance *instance = up_create(&settings);

	up_add_chunk(instance, url, url_len);
	up_complete(instance);
	up_destroy(instance);

	ASSERT_EQUAL(on_begin_called_correctly,1);
	ASSERT_EQUAL(on_protocol_called_correctly, 1);
	ASSERT_EQUAL(on_host_called_correctly, 1);
	ASSERT_EQUAL(on_port_called_correctly, 1);
	ASSERT_EQUAL(on_path_segment_called_correctly, 2);
	ASSERT_EQUAL(on_key_value_called_correctly, 2);

TSET()

TEST_END()