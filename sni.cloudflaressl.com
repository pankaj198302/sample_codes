-----BEGIN CERTIFICATE-----
MIIFJjCCBM2gAwIBAgIQDQxBvyyqkFPb/o2HIG0pnjAKBggqhkjOPQQDAjBKMQsw
CQYDVQQGEwJVUzEZMBcGA1UEChMQQ2xvdWRmbGFyZSwgSW5jLjEgMB4GA1UEAxMX
Q2xvdWRmbGFyZSBJbmMgRUNDIENBLTMwHhcNMjMwMjE0MDAwMDAwWhcNMjQwMjE0
MjM1OTU5WjB1MQswCQYDVQQGEwJVUzETMBEGA1UECBMKQ2FsaWZvcm5pYTEWMBQG
A1UEBxMNU2FuIEZyYW5jaXNjbzEZMBcGA1UEChMQQ2xvdWRmbGFyZSwgSW5jLjEe
MBwGA1UEAxMVc25pLmNsb3VkZmxhcmVzc2wuY29tMFkwEwYHKoZIzj0CAQYIKoZI
zj0DAQcDQgAE/NU/7vfdymScyhfx81ieO8XiwGqqTU4tjeWzSosWSpmQwnGmRqiU
2h2wyT9uYxRme6uQ0yLedf4nz9ks+4OxtKOCA2gwggNkMB8GA1UdIwQYMBaAFKXO
N+rrsHUOlGeItEX62SQQh5YfMB0GA1UdDgQWBBR2lvkrTbuB12n47lnlWaQziHsF
OjAvBgNVHREEKDAmgg1qaWdzYXcudzMub3JnghVzbmkuY2xvdWRmbGFyZXNzbC5j
b20wDgYDVR0PAQH/BAQDAgeAMB0GA1UdJQQWMBQGCCsGAQUFBwMBBggrBgEFBQcD
AjB7BgNVHR8EdDByMDegNaAzhjFodHRwOi8vY3JsMy5kaWdpY2VydC5jb20vQ2xv
dWRmbGFyZUluY0VDQ0NBLTMuY3JsMDegNaAzhjFodHRwOi8vY3JsNC5kaWdpY2Vy
dC5jb20vQ2xvdWRmbGFyZUluY0VDQ0NBLTMuY3JsMD4GA1UdIAQ3MDUwMwYGZ4EM
AQICMCkwJwYIKwYBBQUHAgEWG2h0dHA6Ly93d3cuZGlnaWNlcnQuY29tL0NQUzB2
BggrBgEFBQcBAQRqMGgwJAYIKwYBBQUHMAGGGGh0dHA6Ly9vY3NwLmRpZ2ljZXJ0
LmNvbTBABggrBgEFBQcwAoY0aHR0cDovL2NhY2VydHMuZGlnaWNlcnQuY29tL0Ns
b3VkZmxhcmVJbmNFQ0NDQS0zLmNydDAMBgNVHRMBAf8EAjAAMIIBfQYKKwYBBAHW
eQIEAgSCAW0EggFpAWcAdgDuzdBk1dsazsVct520zROiModGfLzs3sNRSFlGcR+1
mwAAAYZN3tZSAAAEAwBHMEUCIHjvMG/6EHLhWVW5FhU/q9T1aCrfUsqDbzE0UE1O
s03EAiEA7ylo/qWXQw5UCbSRPecD6E8ZHcS5nuDZe6IfN5NxxSYAdQBz2Z6JG0yW
eKAgfUed5rLGHNBRXnEZKoxrgBB6wXdytQAAAYZN3takAAAEAwBGMEQCIH8+A5NA
9pIQrREGeLzsNJ5J7QIYFwc7wj+g79wAB84KAiBZCbjbbwvav2z27ZE3I+Rfz5p8
R6aCGjhG4HP+4XWQTgB2AEiw42vapkc0D+VqAvqdMOscUgHLVt0sgdm7v6s52IRz
AAABhk3e1msAAAQDAEcwRQIgKVHBRhkbKgTgd87C9hb6/Ph8K3lALj5wSnGh4DBS
zAoCIQDubrzOdGfmYE9+INXmLYqJ8zpIo816LzZe6FfgOSSPMDAKBggqhkjOPQQD
AgNHADBEAiB2RKDlNp5Tg61a8yesTGvVR0v5Km2FtnOBJGsN/u8N0gIgFxGsjb8N
JnUw83w0xk4V6wUN8ZamJ+EJcmCPvy1TLJI=
-----END CERTIFICATE-----

// This is GandiStandardSSLCA2.pem, the root Certificate Authority that signed 
// the server certifcate for the demo server https://jigsaw.w3.org in this
// example. This certificate is valid until Sep 11 23:59:59 2024 GMT
const char* rootCACertificate = \
"-----BEGIN CERTIFICATE-----\n" \
"MIIFJjCCBM2gAwIBAgIQDQxBvyyqkFPb/o2HIG0pnjAKBggqhkjOPQQDAjBKMQsw\n" \
"BAMTJVVTRVJUcnVzdCBSU0EgQ2VydGlmaWNhdGlvbiBBdXRob3JpdHkwHhcNMTQw\n" \
"CQYDVQQGEwJVUzEZMBcGA1UEChMQQ2xvdWRmbGFyZSwgSW5jLjEgMB4GA1UEAxMX\n" \
"Q2xvdWRmbGFyZSBJbmMgRUNDIENBLTMwHhcNMjMwMjE0MDAwMDAwWhcNMjQwMjE0\n" \
"MjM1OTU5WjB1MQswCQYDVQQGEwJVUzETMBEGA1UECBMKQ2FsaWZvcm5pYTEWMBQG\n" \
"A1UEBxMNU2FuIEZyYW5jaXNjbzEZMBcGA1UEChMQQ2xvdWRmbGFyZSwgSW5jLjEe\n" \
"MBwGA1UEAxMVc25pLmNsb3VkZmxhcmVzc2wuY29tMFkwEwYHKoZIzj0CAQYIKoZI\n" \
"zj0DAQcDQgAE/NU/7vfdymScyhfx81ieO8XiwGqqTU4tjeWzSosWSpmQwnGmRqiU\n" \
"2h2wyT9uYxRme6uQ0yLedf4nz9ks+4OxtKOCA2gwggNkMB8GA1UdIwQYMBaAFKXO\n" \
"N+rrsHUOlGeItEX62SQQh5YfMB0GA1UdDgQWBBR2lvkrTbuB12n47lnlWaQziHsF\n" \
"OjAvBgNVHREEKDAmgg1qaWdzYXcudzMub3JnghVzbmkuY2xvdWRmbGFyZXNzbC5j\n" \
"b20wDgYDVR0PAQH/BAQDAgeAMB0GA1UdJQQWMBQGCCsGAQUFBwMBBggrBgEFBQcD\n" \
"AjB7BgNVHR8EdDByMDegNaAzhjFodHRwOi8vY3JsMy5kaWdpY2VydC5jb20vQ2xv\n" \
"dWRmbGFyZUluY0VDQ0NBLTMuY3JsMDegNaAzhjFodHRwOi8vY3JsNC5kaWdpY2Vy\n" \
"dC5jb20vQ2xvdWRmbGFyZUluY0VDQ0NBLTMuY3JsMD4GA1UdIAQ3MDUwMwYGZ4EM\n" \
"AQICMCkwJwYIKwYBBQUHAgEWG2h0dHA6Ly93d3cuZGlnaWNlcnQuY29tL0NQUzB2\n" \
"BggrBgEFBQcBAQRqMGgwJAYIKwYBBQUHMAGGGGh0dHA6Ly9vY3NwLmRpZ2ljZXJ0\n" \
"LmNvbTBABggrBgEFBQcwAoY0aHR0cDovL2NhY2VydHMuZGlnaWNlcnQuY29tL0Ns\n" \
"b3VkZmxhcmVJbmNFQ0NDQS0zLmNydDAMBgNVHRMBAf8EAjAAMIIBfQYKKwYBBAHW\n" \
"eQIEAgSCAW0EggFpAWcAdgDuzdBk1dsazsVct520zROiModGfLzs3sNRSFlGcR+1\n" \
"mwAAAYZN3tZSAAAEAwBHMEUCIHjvMG/6EHLhWVW5FhU/q9T1aCrfUsqDbzE0UE1O\n" \
"s03EAiEA7ylo/qWXQw5UCbSRPecD6E8ZHcS5nuDZe6IfN5NxxSYAdQBz2Z6JG0yW\n" \
"eKAgfUed5rLGHNBRXnEZKoxrgBB6wXdytQAAAYZN3takAAAEAwBGMEQCIH8+A5NA\n" \
"9pIQrREGeLzsNJ5J7QIYFwc7wj+g79wAB84KAiBZCbjbbwvav2z27ZE3I+Rfz5p8\n" \
"R6aCGjhG4HP+4XWQTgB2AEiw42vapkc0D+VqAvqdMOscUgHLVt0sgdm7v6s52IRz\n" \
"AAABhk3e1msAAAQDAEcwRQIgKVHBRhkbKgTgd87C9hb6/Ph8K3lALj5wSnGh4DBS\n" \
"zAoCIQDubrzOdGfmYE9+INXmLYqJ8zpIo816LzZe6FfgOSSPMDAKBggqhkjOPQQD\n" \
"AgNHADBEAiB2RKDlNp5Tg61a8yesTGvVR0v5Km2FtnOBJGsN/u8N0gIgFxGsjb8N\n" \
"JnUw83w0xk4V6wUN8ZamJ+EJcmCPvy1TLJI=\n" \
"-----END CERTIFICATE-----\n";