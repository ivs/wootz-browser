# isolated-context

This suite runs tests with
`--isolated-context-origins=https://web-platform.test`.

As of 2024-05-04, there's one test in this suite:
  - `wpt_internal/permissions-policy/`: Verify that the IWA-specific
    APIs are included in the permissions policy results. These APIs
    should only be available in an isolated context which this test
    runs under. See `//third_party/blink/web_tests/VirtualTestSuites`
    for where that's configured.
